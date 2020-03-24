## Purpose
In this tutorial I will be showing you how to do the following:
<br/>&nbsp;&nbsp;&nbsp; Compile using command Line
<br/>&nbsp;&nbsp;&nbsp; Redirect input using command line
<br/>&nbsp;&nbsp;&nbsp; Submit a solution to vjudge
<br/><br/>
These are all basic and essential skills when both solving vjudge problems and preparing for Computer Science Competitions.
I will approach this using a follow along format.

## Grabbing a problem
Let's start by finding and starting on a vjudge problem. To do this you will first need to go to the 
[vjudge website](https://vjudge.net/). Then click on the problems tag. We're going to be using UVA Problem
number 11172 (Relational-Operators) as a simple starting example. So plug in the problem number in the "prob" section
and click the link to the problem. While not required it might be a good idea to download the pdf version of the
problem and put it in the folder you plan to work in. Sometimes the pdf and image links
brake on these websites, in this case look next to the title of the problem there is a link to the origin site of the problem, go
there to get the problem. We will however still submit the problem using vjudge, it is just that sites this large are sometimes
hard to maintain and manage and links and files fall into disrepair. Cool now you have the problem and perferably the pdf of the
information for said problem.

## Solving the problem
Now read over the problem and think of a solution. Once you have an idea in your head of how you might go about solving this
problem go ahead and type it up in what ever your favorite code editor is. Try to come up will your own solution but when your
done compare it to the solution I used and see if there are any diffrences. If there is that by no means says yours is wrong or
even worse, just different. Thats what makes these problems great, there are often alot of diffrent ways of approaching them and diffrent
people will go about them diffrently.
```cpp
//Team Test that everyone can compile, redirect io and submit to vjudge
//-----PreCompiler Directives-----
#include<iostream>

//-----main-----
int main (){
    int numSet;     //tracks the size of our dataset
    int numOne;     //stores our first number to compare
    int numTwo;     //stores our second number to compare

    //grab size of our dataset
    std::cin >> numSet;

    for (int i = 0; i < numSet; i++){
        //grab our numbers
        std::cin >> numOne >> numTwo;
        //compare our numbers
        if (numOne < numTwo){
            std::cout << '<' << '\n';
        } else if (numOne > numTwo){
            std::cout << '>' << '\n';
        } else {
            std::cout << '=' << '\n';
        }
    }
}//end of main
```


## Compiling through Command Line
Alright so now we have a solution but we need to test it. We do this by first compiling the code and then by running it
like your probably used to however here we're going to do so manually through command line instead of using an IDE's automatic
tool to compile and run our code for us. To do this you will first need a system with a compiler installed on it for the
language being used. In my case I'm going to use g++ as we will mostly likely always be using for these sorts of problems
as we will probably always use c++. With that said if you don't feel like looking up a tutorial on installing a compiler
[repl.it](https://repl.it/) has g++ preinstalled so go there and open a repl. Some compilers will have slightly different commands
or possible parameters but they'll most likely be similar the g++. First we put the name of our compiler, the name of the
file to compile and then -o signaling we're telling it what to name the compiled file and lastly the desired name for the
compiled file. Here is an example: <br/> g++ main.cpp -o main.out <br/> <b>Note: you don't have to use the .out extension it is just
what I use.</b> Cool so now we have our compiled file to run it simply do ./theNameOfYourFile, in my case that is ./main.out . After 
that type in a set of test data to see if your program is running as you expect it to and make sure your getting the 
right answers.

## Redirecting Input using Command Line
Now that we know we have a working solution using our own test and maunally inputting the numbers lets go ahead and prepare it 
to be summited. To fully test and make sure that our program will work for vjudge we are going to use the same testing method
they do. Since they can't have you read in from a file since you don't know the test inputs file name to hard code it, and they certainly
aren't going to have someone sit there and manually type into a keyboard, they use something call input redirection (similar to 
piping but not the same). To do this first create a file holding your test input data, I suggest the provided test data under
example input. Once you have that to redirect simply put in the command to run your compiled file and add < and your input file name.
Example <br/>./main.out < input.dat <br/> hit enter and it will run the program using the input from input.dat (or whatever the
name of your file is). Make sure the output you receive is the same as the output listed in example out matching to the line, letter
and capitalization.

## Submitting to vJudge
Now that we have a well tested solution lets go and submit it to vjudge to make 100% we got it right. First you'll need an account,
so go ahead and create one and log in if you don't already have one. Once you've done that go ahead and click submit. Set the Language
to what ever language you used, in our case it is c++, copy over your solution and sumbit it. After that you'll have to wait for a 
minute or two for it to process and it really can take a minute or two. Hopfully it says it was right and we can celebrate a problem
well solved, if not look back over the problem carfully and make sure there are no details or possible test cases you missed.
Lastly and most importantly have fun with it.
