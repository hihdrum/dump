-module(dump).

%% API exports
-export([main/1]).

%%====================================================================
%% API functions
%%====================================================================

readBytePrint() ->
  Char = io:get_chars('', 1),
  case Char of
    {error, _} -> ok;
    eof        -> ok;
    _          -> io:format("~*.*.*b ", [2, 16, $0, hd(Char)]),
                  readBytePrint()
  end.

%% escript Entry point
main(_Args) ->
    readBytePrint(),
    erlang:halt(0).

%%====================================================================
%% Internal functions
%%====================================================================
