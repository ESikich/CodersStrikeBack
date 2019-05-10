# CodersStrikeBack
Coders Strike Back challenge on codingame.com

<b>Rules</b></br>
The circuit of the race is made up of checkpoints. To complete one lap, your vehicle (pod) must pass through each checkpoints in order and back through the start. The first player to reach the starting checkpoint on the final lap wins.

<b>The pods work as follows:</b><br/>
To pass a checkpoint, the center of a pod must be inside the radius of the checkpoint.
To move a pod, you must print a target destination point followed by a thrust value. Details of the protocol can be found further down.
The thrust value of a pod is its acceleration and must be between 0 and 100.
You can use 1 acceleration boost in the race, you need only replace the thrust value by the BOOST keyword.
The pods have a circular force-field around their center, with a radius of 400 units, which activates in case of collisions with other pods.

<b>Game Input</b></br>
<b>Input for one game turn</b></br>

First line: 6 integers x & y for your pod's position. nextCheckpointX & nextCheckpointY for the coordinates of the next checkpoint the pod must go through. nextCheckpointDist for the computed distance between your pod and the next checkpoint, nextCheckpointAngle for the angle in degrees between your pod orientation and the direction of the next checkpoint (from -180 to 180).

Second line: 2 integers opponentX & opponentY for the opponent pod's position.

<b>Output for one game turn</b><br/>
One line: 2 integers for the target coordinates of your pod followed by thrust, the thrust to give to your pod. You may replace the thrust value by BOOST.

<b>Constraints</b><br/>
0 ≤ thrust ≤ 100
Response time first turn ≤ 1000ms
Response time per turn ≤ 75ms
