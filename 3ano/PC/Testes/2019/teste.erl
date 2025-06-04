-module(teste).
-export([start/0, participa/0, jogo/1, createPartida/1, adivinha/2]).

start() ->
    Pid = spawn(fun() -> jogo([]) end),

    register(jogo_pid, Pid).

participa() ->
    jogo_pid ! {participa, self()}

    receive Msg -> Msg
    end.


jogo(Pids) ->
    receive
        {participa, Pid} ->
            NewPids = [Pid | Pids],

            case length(Pids) of 
                4 ->
                    createPartida(NewPids),
                    jogo([]);
                _ -> 
                    jogo(NewPids)
            end;
        end;
    end.

createPartida(Pids) ->
    P = spawn(fun() -> partida(100, rand:uniform(100)) end),
    [Pid ! P || Pid <- Pids],
    spawn(fun() ->
        receive
            after 60000 ->
                P ! partidaOver("TEMPO")
            end
        end,
    end)

adivinha(N, Partida) ->
    Partida ! {N, self()},
    receive Msg -> Msg
    end.

partida(Tries, Num) ->
    receive
        {N, Pid} ->
            if 
                N == Num ->
                    Pid ! "GANHOU",
                    partidaOver("PERDEU");
                N < Num ->
                    Pid ! "MAIOR",
                    partida(Tries-1, Num);
                N > Num ->
                    Pid ! "MENOR",
                    partida(Tries-1, Num);
            end;
        partidaOver ->
            partidaOver("TEMPO");
    end.


partidaOver(Status) ->
    receive
        {_, Pid} ->
            Pid ! Status,
            partidaOver(Status);
        _ ->
            partidaOver(Status);
        partida(0, _) ->
            partidaOver("TENTATIVAS")
    end.