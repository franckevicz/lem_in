# lem_in

The whole task are in [this pdf](https://github.com/franckevicz/lem_in/blob/master/lem-in.en.pdf).
Here is just quick explanation.

The goal of this project is to find the quickest way to get ants across the farm.

Obviously, there are some basic constraints. To be the first to arrive, ants will need to take the shortest path (and that isn’t necessarily the simplest). They will also need to avoid traffic jams as well as walking all over their fellow ants.
At the beginning of the game, all the ants are in the room ##start. The goal is to bring them to the room ##end with as few turns as possible. Each room can only contain one ant at a time. (except at ##start and ##end which can contain as many ants as necessary.)

At each turn you can move each ant only once and through a tube (the room at the receiving end must be empty).

Program will receive the data describing the ant farm from the standard output in the following format:

+number_of_ants
+the_rooms
+the_links

Here is an example of the farm
```
##start
1 23 3
2 16 7 #comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
```

Where `1 23 3`:

`1` - Name of room
`23` - It's X coord
`3` - It's Y coord

And `0-4`
It's a link between room with name `0` and `4`

The exapmle of how it should work:
```
zaz@blackjack /tmp/lem-in $ ./lem-in < subjet2.map
3
2 5 0 
##start
0 1 2 
##end
1 9 2 
3 5 4
0-2
0-3
2-1
3-1
2-3

L1-3 L2-2
L1-1 L2-1 L3-3
L3-1
```
Where: `L1-3`:

`L` - lem(ant)
`1` - number of ant
`3` - name of room where it move
