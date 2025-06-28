# k-algorithm-random-number-generator
k algorithm random number generator

this is a random number generator inspired by the art of computer science v2

it has  the following step:

K1[Choose number of iterations]  Set Y Y=X/10^9 Y is most significant digit of X.

K2. Set Z Z=[X/10^8] mod 10 , Z is the second most significant digit of X. Go to step K(3 + Z). ( now jump to a random
step in the program.)

K3. [Ensure >= 5 x 10^9 ]  If X < 5000000000, set X=X + 5000000000.

K4. [Middle square.] Replace X by (X^2/10^5) mod 10^10, that is, by the middle

of the square of X

K5. [Multiply.] Replace X by (1001001001 X) mod 1010

K6. [Pseudo-complement.] If X < 100000000, then set X= X + 9814055677 otherwise set X= 10^10-X

K7. [Interchange halves.] Interchange the low-order five digits of X with the

high-order five digits; that is, set X= 10^5*( X mod 10^5) + X/10^5,  the

middle 10 digits of (10^10 + 1)* X

K8. [Multiply.] Same as step K5.

K9. [Decrease digits.] Decrease each nonzero digit of the decimal representation of X by one.

Kl0. [99999 modify.] If X < 10^5 , set X = X^2 + 99999; otherwise set X = X^2 - 99999

K11. [Normalize.] (At this point X cannot be zero.) If X < 10^9 , set X = 10X and repeat this step.

K12. [Modified middle square.] Replace X by [X(X-1)/10^5] mod 10^10, that

is, by the middle 10 digits of X(X - 1).

K13. [Repeat] If Y > 0, decrease Y by 1 and return to step K2. If Y = 0, the

algorithm terminates with X as the desired "random" value.