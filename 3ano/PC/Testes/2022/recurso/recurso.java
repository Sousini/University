/*
1- Starvation acontece quando uma ou mais threads não conseguem aceder a recursos necessários porque outras threads estão constantemente a obter prioridade e a ocupar os recursos.

Um cenário típico é o uso de um lock com política injusta, onde as threads são servidas sem ordem. Por exemplo, se várias threads competem por um recurso e uma thread de alta prioridade o adquire repetidamente, outra thread de prioridade inferior pode nunca ter a oportunidade de executar, mesmo estando pronta, o que resulta em starvation.
*/

/*
2- Estas generalizações de semáforos permitem adquirir ou libertar várias unidades do recurso de uma só vez. 

acquire(n) tenta obter n unidades do semáforo. A thread bloqueia se o valor atual for inferior a n.

release(n) liberta n unidades, aumentando o valor do semáforo em n.

Comparado com as operações clássicas (wait/signal) que operam apenas uma unidade de cada vez, as generalizações de semáforos com acquire(n) e release(n) são mais flexíveis e úteis quando threads precisam de múltiplos recursos simultaneamente.
*/

/*
3- O wait() deve ser feito dentro de um ciclo que (re)testa um predicado devido ao fenómeno spurious wakeups em que uma thread pode acordar sem ter sido notificada ou sem que a condição que ela esperava se tenha tornado verdadeira. 
Assim, é essencial reavaliar a condição para garantir correção e segurança da sincronização.
*/

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class recurso {
    interface Controller {
        int request_resource(int i);
        void release_resource(int i);
    }

    class MonitorController implements Controller {
        private final int T;
        private int[] resources = new int[2];
        private int currentResource = -1;
        private final Lock lock = new ReentrantLock();
        private final Condition[] canAccess = new Condition[2];
        private final Condition canChange = lock.newCondition();


        public MonitorController(int T) {
            this.T = T;
            for(int i = 0; i < 2;i++) {
                canAccess[i] = lock.newCondition();
            }
        }

        public int request_resource(int i) {
            lock.lock();
            try {
                while((currentResource != -1 && currentResource != i) || (currentResource == i && resources[i] >= T)) {
                    canAccess[i].await();
                }

                if(currentResource == -1) {
                    currentResource = i;
                }
                resources[i]++;
                return i;
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return -1;
            
            } finally {
                lock.unlock();
            }
        }

        public void release_resource(int i) {
            lock.lock();
            try {
                resources[i]--;
                if(resources[i] == 0) {
                    currentResource = -1;
                    canChange.signalAll();
                    canAccess[0].signalAll();
                    canAccess[1].signalAll();
                } else {
                    canAccess[i].signal();
                }
            } finally {
                lock.unlock();
            }
        }
    }

}