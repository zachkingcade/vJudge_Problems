## Purpose
Today I'll be giving you a basic run down of the tools used in programming team, how to install them and how to use them.
We will go over the following topics:
<br/>&nbsp;&nbsp;&nbsp; How to Install Mingw W64
<br/>&nbsp;&nbsp;&nbsp; Grabbing a UVA Problem
<br/>&nbsp;&nbsp;&nbsp; Solving The UVA Problem
<br/>&nbsp;&nbsp;&nbsp; Compiling using command Line
<br/>&nbsp;&nbsp;&nbsp; Redirect input using command line
<br/>&nbsp;&nbsp;&nbsp; Submit a solution to vjudge
<br/><br/>
These are all basic and essential skills when both solving vjudge problems and preparing for Computer Science Competitions.
I will approach this using a follow along format both on this paper and during our first meeting of the semester.

## How to Install Mingw W64
Go to https://www.mingw-w64.org/.<br/>
Navigate to the downloads tab.<br/>
In the table find MingW-W64-builds and click it, this should take you further down the page where you will find a link to a
source forge page, follow that link.<br/>
Download the installer, once the download is finished click the installer to run it. Most the options here are not super important
however do remember where you have Mingw W64 installed.<br/>
Now that you have it "installed" if you go to command line and try typing in gcc or g++ you'll notice you get the message "command not found"
this is because we have not yet added the newly installed commands to path so the computer can find them when looking for commands for command
line. <br/>
If you go look where you installed Mingw W64 inside that there is going to be a folder labeled "bin", this contains all our actual commands. We
want to add this to the computers PATH. To do this take down the path to get to that folder, this can be done via right clicking, going to properties
and copying location (make sure it ends in \bin, on some systems you will need to add this if you right clicked the bin folder as it will not include
it's self).<br/>
Now type in the start menu path and click "Edit the system environment varibles".<br/>
Now click "Environment Varibles", click the PATH section of the table and hit edit at the bottom.<br/>
Now click add to add a new section to the PAth and paste your path to your bin folder.<br/>
Now when you go to command line and try g++ or gcc you should get a message a about missing input file, for now this is what we want to happen.<br/>

## Grabbing a problem
Let's start by finding and starting on a vjudge problem. To do this you will first need to go to the 
[vjudge website](https://vjudge.net/). Then click on the problems tab. We're going to be using UVA Problem
number 11172 (Relational-Operators) as a simple starting example. So plug in the problem number in the "prob" section
and click the link to the problem. While not required it might be a good idea to download the pdf version of the
problem and put it in the folder you plan to work in. Not always but sometimes the pdf and image links
brake on these websites, in this case look next to the title of the problem there is a link to the origin site of the problem, go
there to get the problem. We will however still submit the problem using vjudge, it is just that sites this large are sometimes
hard to maintain and manage and links and files fall into disrepair. Cool now you have the problem and perferably the pdf of the
information for said problem.

## Solving the problem
Now read over the problem and think about a solution. It might help to seperate and write down what information you have, what input you get 
and what output you need from that input. Once you have an idea in your head of how you might go about solving this
problem go ahead and type it up in what ever your favorite code editor is. Try to come up with your own solution but when your
done it can be useful to compare to other members to see how we might have done it diffrently. If there is diffrence that by no means says yours is wrong or
even worse, just different. Thats what makes these problems great, there are often alot of diffrent ways of approaching them and diffrent
people will go about them diffrently.
```cpp
//Team Test that everyone can compile, redirect io and submit to vjudge
//-----PreCompiler Directives-----
#include<iostream>

//-----main-----
int main (){
    int numSet;     //tracks the size of our dataset

    //grab size of our dataset
    std::cin >> numSet;

    for (int i = 0; i < numSet; i++){
        int numOne, numTwo;
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
like your probably used to. However here we're going to do so manually through command line instead of using an IDE's automatic
tool to compile and run our code for us. To do this you will first need a system with a compiler installed on it for the
language being used. In my case I'm going to use g++ as we will mostly likely always be using c++ for these sorts of problems.
First we put the name of our compiler, the name of the file to compile and then -o signaling we're telling it what to name the 
compiled file and lastly the desired name for the compiled file. Here is an example: <br/>
g++ main.cpp -o main.out <br/>
 <b>Note: you don't have to use the .out extension it is just what I use.</b>
Cool so now we have our compiled file to run it simply do ./theNameOfYourFile, in my case that is ./main.out . After that type in a set of test data to see if your program is running as you expect it to and make sure your getting the right answers.

## Redirecting Input using Command Line
Now that we know we have a working solution using our own test and maunally inputting the numbers lets go ahead and prepare it 
to be summited. To fully test and make sure that our program will work for vjudge we are going to use the same testing method
they do. Since they can't have you read in from a file since you don't know the test inputs file name to hard code it, and they certainly
aren't going to have someone sit there and manually type into a keyboard, they use something call input redirection (similar to 
piping but not the same). To do this first create a file holding your test input data, I suggest the provided test data under
example input. Once you have that to redirect, simply put in the command to run your compiled file and add < and your input file name.
Example <br/>
./main.out < input.dat <br/>
 hit enter and it will run the program using the input from input.dat (or whatever the
name of your file is). Make sure the output you receive is the same as the output listed in example out.

## Submitting to vJudge
Now that we have a well tested solution lets go and submit it to vjudge to make 100% we got it right. First you'll need an account,
so go ahead and create one and log in if you don't already have one. Once you've done that go ahead and click submit. Set the Language
to what ever language you used, in our case it is c++, copy over your solution and sumbit it. After that you'll have to wait for a 
minute or two for it to process and it really can take a minute or two. Hopfully it says it was right and we can celebrate a problem
well solved, if not look back over the problem carfully and make sure there are no details or possible test cases you missed.
Lastly and most importantly have fun with it.
