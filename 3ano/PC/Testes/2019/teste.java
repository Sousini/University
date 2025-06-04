

/*
1- Starvation é o fenómeno em que uma thread ou um processo não consegue aceder a um recurso pois este está a ser usado por outros processos que têm prioridade ou estão constantemente a consumir o recurso. 

Um cenário propício à ocorrência deste fenómeno pode ser, por exemplo, quando temos um sistema com várias threads acedendo a uma fila de impressão compartilhada. Esta fila usa lock para controlar o acesso e as threads de prioridade alta são sempre atendidas primeiro, uma thread de prioridade baixa tenta aceder à fila e nunca consegue pois é sempre passada por uma thread de prioridade maior. Ao acontecer isto a thread de prioridade baixa vai sofrer starvation pois nunca imprime nada.

A solução a optar para este caso é a espera limitada, existindo um número de vezes que outros processos podem entrar passando à frente de um processo que já pediu entrada, ou seja, implementar aging, onde a prioridade de uma thread aumenta quanto mais tempo ela espera. 
*/

/*
2- Ter mais do que uma variável de condição num monitor permite que diferentes grupos de threads esperem por condições diferentes dentro do mesmo bloco sincronizado (ou seja, com o mesmo lock). 

Dando o exemplo de produtor-consumidor, podemos ter: 
 - uma condição filaCheia, onde os produtores esperam se a fila estiver cheia
 - uma condição filaVazia, onde os consumidores esperam se a fila estiver vazia

Assim só acordamos as threads necessárias, se um consumidor consome um item acordamos um produtor (a fila deixou de estar cheia); se um produtor produz um item acordamos um consumidor (a fila deixou de estar vazia). 

Isto melhora a eficiência e evita que threads sejam acordadas sem necessidade.

Ao usar vários monitores separados cada um vai ter o seu próprio lock. Isto quebra a exclusão mútua sobre o recurso compartilhado, podendo causar race conditions e inconsistência no estado. O uso de vários locks também pode causar deadlocks, quando uma thread espera por um lock que outra thread já possui, criando uma espera circular onde nenhuma thread pode continuar. Além disso, a sincronização entre condições relacionadas seria mais difícil e menos segura.

*/

/*
3- Java usa threads compartilhando memória e sincronização através de monitores (synchronized,wait/notify). A abstração concorrente é baseada no controlo explícito de acesso a recursos compartilhados.

Erlang usa processos leves isolados que comunicam por troca de mensagens assíncronas. Não há memória compartilhada e a concorrência é implícita no modelo de atores. Cada processo tem o seu próprio estado e só pode modificá-lo comunicando-se com outros apenas por mensagens.

Assim, Java aposta em concorrência por compartilhamento e sincronização, enquanto Erlang segue o modelo de isolamento e comunicação por mensagens, mais adequado para sistemas distribuídos e tolerantes a falhas.
*/

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;


public class teste {
    public interface Jogo {
        Partida participa();
    }

    public interface Partida {
        String adivinha(int n);
    }

    Lock lock = new ReentrantLock();
    Condition cond = ;
    int numPlayers = 0;
    Partida curr = ;

    Partida participa() {
        lock.lock();
        try {
            numPlayers++;
            Partida myPartida = curr;
            if(numPlayers < 4) {
                while (myPartida == curr) {
                    cond.await();
                }
            } else {
                cond.signalAll();
                numPlayers = 0;
                curr = new Partida();
            }
            return myPartida;
        }
        finally {
            lock.unlock();
        }
    }
    
    
    public class Partida {
        int tries = 100;
        int num = 23;
        
        long start = System.currentTimeMillis();
        
        Lock lock = new ReentrantLock();
        
        bool won = false;
        
        public String adivinha(int n) {
            lock.lock();
            
            try {
                if(won) {
                    return "PERDEU";
                }
                if(tries == 0) {
                    return "PERDEU";
                }
                if(System.currentTimeMillis() - start > 60000) {
                    return "TEMPO";
                }
                if(n == num) {
                    won = true;
                    return "GANHOU";
                } else if (n < num) {
                    tries--;
                    return "MAIOR";
                } else {
                    tries--;
                    return "MENOR";
                }
            } finally {
                lock.unlock();
            }
        }
    }
}