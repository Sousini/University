/*
1 - Um deadlock é um fenómeno onde duas ou mais threads ficam bloqueadas indefinidamente, porque cada uma está à espera de um recurso que a outra já possui, formando um ciclo de dependência que impede todas de avançar.

O deadlock ocorre geralmente quando estas quatro condições estão presentes simultaneamente:

 1 - Exclusão Mútua: os recursos só podem ser usados por uma thread de cada vez
 
 2- Posse e Espera: uma thread mantém um recurso enquanto espera por outro

 3- Não preempção: os recursos não podem ser retirados à força de uma thread

 4- Espera circular: há uma cadeia circular de threads, onde cada uma espera por um recurso que a próxima detém.


Isto pode acontecer quando, por exemplo, suponhamos que duas threads, T1 e T2, acedem a dois recursos partilhados, A e B. T1 adquire o recurso A, depois tenta adquirir o recurso B. Ao mesmo tempo, T2 adquire o recurso B, depois tenta adquirir o recurso A. Se T1 e T2 fizerem isso ao mesmo tempo, cada uma fica à espera que a outra liberte o recurso de que precisa, não avançando nenhuma e ocorrendo o deadlock.

*/


/*
2- Nos monitores clássicos é garantido que, se estiver algum processo bloqueado num wait, a seguir a um signal prossegue o processo bloqueado, assim, se o predicado é verdadeiro quando é feito o signal permanece verdadeiro quando o wait retorna; mais tarde prossegue quem fez o signal; finalmente podem entrar outros processes (imediate resumption requirement ou signal and urgent wait). 

Nos monitores modernos, contrariamente aos clássicos, primeiro continua o processo que faz signal e depois pode correr o processo acordado ou um terceiro processo que estivesse a querer entrar.

Sendo uma barreira reutilizável uma estrutura onde várias threads esperam até todas chegarem a um ponto comum antes de prosseguir, em monitores modernos é difícil garantir que todas as threads saiam da barreira ao mesmo tempo, pois acordam uma a uma e precisam readquirir o lock. Além disso, é necessário evitar que threads de uma nova rodada interfiram com as que ainda estão a sair da rodada anterior.
*/

/*
3- O selective receive em Erlang permite que um processo escolha qual mensagem processar da sua caixa de correio, com base em padrões específicos. Em vez de obrigar o processo a tratar sempre a primeira mensagem recebida, o processo pode ignorar temporariamente mensagens que não correspondam ao padrão desejado e esperar por uma mais relevante.

Esta funcionalidade é útil quando um processo lida com diferentes tipos de mensagens e precisa dar prioridade a algumas ou aguardar por uma resposta específica, mesmo que outras mensagens tenham chegado antes. O selective receive facilita a implementação de protocolos de comunicação mais complexos, melhora o controlo sobre a execução concorrente e evita a necessidade de estruturas auxiliares de filtragem.

Assim, o selective receive torna o modelo de concorrência de Erlang mais flexível e expressivo, sem comprometer o isolamento entre processos.
*/

import java.util.List;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;




public class teste {
    interface MatchMaker {
        BoundedBuffer waitForConsumer();
        BoundedBuffer waitForProducer();
    }

    class MatchMaker {
        List<WaitRecord> lp;
        List<WaitRecord> lc;
        Lock lock = new ReentrantLock();

        class WaitRecord {
            BoundedBuffer b = new BoundedBuffer();
            Condition cond = lock.newCondition();
            boolean done = false;
        }

        BoundedBuffer waitForConsumer() {
            lock.lock();

            try {
                if(lc.isEmpty()) {
                    WaitRecord w = new WaitRecord();
                    lp.add(w);
                    while(w.done == false) {
                        w.cond.await();
                    }
                    return w.b;
                } else {
                    WaitRecord w = lc.remove(0);
                    w.done = true;
                    w.cond.signal();
                    return w.b;
                }

            } finally {
                lock.unlock();
            }
        }

        BoundedBuffer waitForProducer() {
            lock.lock();

            try {
               if(lp.isEmpty()) {
                WaitRecord w = new WaitRecord();
                lc.add(w);
                while(w.done == false) {
                    w.cond.await();
                }
                return w.b;
               } else {
                WaitRecord w = lp.remove(0);
                w.done = true;
                w.cond.signal();
                return w.b;
               }
            } finally {
                lock.unlock();
            }
        }
    }


}
