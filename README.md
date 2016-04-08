##ConnectX Game
###Description
The ConnectX Game is variation of the board game "Connect Four"
###Bug Report
* Bug in bool inBounds(int, int) function: The bug is inside private function bool inBounds(int, int), invalid width i.e negatively invalid or positively invalid width is not handled properly. Repercussions of this bug are found in Public member function at(int, int) if we try asking invalid width query to at function it is expected to return -1 for invalid location but it doesn't return -1.

* Bug in void placePiece(int) function: This bug is present inside the placePiece(int) function, and occurs when invalid column is passed, what happens is it silently ignores the invalid location but still toggleTurn() is called. Therefore producing the repercussion that turn changes (which it should not) for invalid parameter to placePiece(int).
