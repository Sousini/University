-module(recurso).
-export([start/1, request/2, release/2]).

start(T) ->
    spawn(fun() -> init(T) end).

init(T) ->
    loop(#{t => T, res0 => 0, res1 => 0, current => none}).

loop(State = #{t := T, res0 := R0, res1 := R1, current := Current}) ->
    receive
        {request, Pid, Res} when Res =:= 0 orelse Res =:= 1 ->
            case can_access(Res, Current, R0, R1, T) of
                true ->
                    NewState = update_state(Res, State),
                    Pid ! {granted, Res},
                    loop(NewState);
                false ->
                    loop(State)
            end;
        {release, Pid, Res} ->
            NewState = case Res of 
                0 -> State#{res0 := R0 - 1};
                1 -> State#{res1 := R1 - 1};
            end,

            FinalState = case {Res, maps:get(res0, NewState), maps:get(res1, NewState)} of 
                {0, 0, _} when Current =:= 0 -> NewState#{current := none};
                {1, _, 0} when Current =:= 1 -> NewState#{current := none};
                _ -> NewState
            end,
            Pid ! released,
            

            loop(FinalState)
        end.
can_access(0, none, _, _, _) -> true;
can_access(1, none, _, _, _) -> true;
can_access(0, 0, R0, _, T) -> R0 < T;
can_access(1, 1, _, R1, T) -> R1 < T;
can_access(_, _, _, _, _) -> false.

update_state(0, State = #{res0 := R0}) -> State#{current := 0, res0 := R0 + 1};
update_state(1, State = #{res1 := R1}) -> State#{current := 1, res1 := R1 + 1}.

request(Controller, Resource) ->
    Controller ! {request, self(), Resource},
    receive
        {granted, Res} -> Res
    end.

release(Controller, Resource) ->
    Controller ! {release, self(), Resource},
    receive
        released -> ok
    end.