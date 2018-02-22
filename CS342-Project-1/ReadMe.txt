**********************HOW TO RUN THE PROGRAM***********************

-bert.cs.uic.edu //Or something similar
-make 
-java ExamTester  
-The questions will be printed along with the possible answers
-The questions and answers will be shuffled printed again.
-For question 1 if the answer is a, the user inputs 1, if b 2, if c 3...ENTER.
-Repeat prosses 5 times until all questions are answered.
-Exam grade will be displayed. 5 points for a corect selection, -5 for an incorrect one.


**********************OTHER STUFF/MORE DETAIL***********************

My program should work as described in the handout to the best of my knowledge. It consists of three classes contained in three Java files. They are linked using a makefile (comand make). The ExamTester class which cointains main() serves as a demonstration of how the program works by creating a 5 question sample exam. Each question has 5 answers. The users are promted to select an answer for each question from a-e by inputing integers 1-5 and pressing Enter after each input. Each question is worth 0 points if unselected (Only possible manually in my exam tester class by disableing the input for said question), 5 questions if the correct answer is selected and -5 if an incorrect answer is selected. Correct Answers are; 
Vilnus Lithuenia: Berlin, Germany: Sofia, Bulgaria: Oslo, Norway and Amsterdam, Netherlands. The exam tester class calls methods from each of the three classes to create the complete exam. The exam class uses the question class and the answer class and so on. Everything is pretty much exactly as described in the handout.  

