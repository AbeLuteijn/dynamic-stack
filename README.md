# Dynamic Stack in C
I wanted to make a stack in C, where the data members could have any size. So I needed a solution where I could push data on a stack, where the pointer to the data could vary in size. I also wanted to learn more about `void*`, so I incorperated some of it.

It might not be the best thing ever, but it's mine. That is what counts.

# References
I once saw a video of a guy implementing a dynamic array in the same kind of style. But he used marco's for it, which I didn't like. Even though the usage might be cleaner with a macro, I just kind of dislike macro's for more complex functions. He had to do some ugly workarounds in the macro itsself to make it work. Here, we don't have to do that.
