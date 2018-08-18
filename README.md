# Intro
It was my school project written in few hours without many comments (yeah, it was hell second day ...) during end of spring 2018.

Also during that time my company servers went down, so a very nice 1 hour trip had been made to our HQ (I left house at 22:00). Then we found out everything is ok, just Internet went down. In entire area and only for our ISP. Thanks coffee!

Have fun! :-)


## What is the Knight's Tour?
It is a known chess problem - travel with Knight all over chessboard, but you can stand on every square only once. For those who are interested https://en.wikipedia.org/wiki/Knight%27s_tour.

## Warnsdorff's rule
### About
One of the solutions. Basically, every time you are moving to square, which has the fewest free neighbours (free == you were not there yet). There can be equal count of neighbours and in this case it is up for player, which path will be taken (random/first/last/... neighbour).
### Algorithm
1. Reset chessboard
2. Set Knight starting position. Increment moves counter. Set moves counter value to the current position.
3. Check free neighbours and their neighbours (have no value)
4. Choose next position which has least neighbours
5. Move Knight to the new position and increment counter. Set moves counter value to the current position.
6. Repeat 3-5 until way is found or neighbours do not exists.

Solution exists when:
* moves counter value == (chessboard width * chessboard height)
* Every position on chessboard has its value (move number) which is greater then zero and maximum value is equal to moves counter
