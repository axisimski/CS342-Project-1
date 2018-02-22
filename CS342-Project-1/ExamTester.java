import java.util.Scanner;

/*Alexander Simeonovski, asimeono
A class containing main which demonstrates how the program works.
It creates an exam ex1.
Than it creates 5 questions and their answers.
They are input in the exam.
It than answers the questions (pre-selected answers).
Finally it shuffles the exam
and returns the total grade (should be 15).
5 points are given for each correctly selected answer.
-5 points are given for each incorrectly selected answer.
The example here requires the input of integers (1-5)
Where 1 is a, 2 is b, 3 is c, 4 is d, 5 is e.
Correct Answers are; 
Vilnus Lithuenia: Berlin, Germany: Sofia, Bulgaria: Oslo, Norway and Amsterdam, Netherlands*/


public class ExamTester {

	public static void main(String[] args) {
		 
		//Prints name and netid
		System.out.println("Alexander Simeonovski\nnetid:asimeo2\n");
	
		//Creates an exam
		Exam ex1 = new Exam("Select a correct answer for 5 points 1 for a, 2 for b...5 for d.\n"
				+ "If you selct an incorrect answer you loose 5 points\n\n");
	
		//Create a question and a bunch of possible answers for it.
		Question q1=new Question("What is the capital of Germany?\n");		
			Answer a= new Answer("Vienna");
	 		Answer b= new Answer("Munich");
	 		Answer c= new Answer("Frankfurt");
	 		Answer d= new Answer("Zurich");
	 		Answer e= new Answer("Berlin");
	 	
	 		
	 		//Set a value for each answer based on correctness.
	 		a.setValue(0, -5);
	 		b.setValue(0, -5);
	 		c.setValue(0, -5);
	 		d.setValue(0, -5);
	 		e.setValue(0, 5);
	 	
	 		//Add answers to question
	 		q1.AddAnswer(a);
	 		q1.AddAnswer(b);
	 		q1.AddAnswer(c);
	 		q1.AddAnswer(d);
	 		q1.AddAnswer(e);
		
		//Create a question and a bunch of possible answers for it.
		Question q2=new Question("What is the capital of Lithuena?\n");
	 		Answer a2= new Answer("Kalunius");
	 		Answer b2= new Answer("Vilnus");
	 		Answer c2= new Answer("Riga");
	 		Answer d2= new Answer("Talin");
	 		Answer e2= new Answer("Litus");
	 		
	 		//Set a value for each answer based on correctness.
			a2.setValue(0, -5);
	 		b2.setValue(0, 5);
	 		c2.setValue(0, -5);
	 		d2.setValue(0, -5);
	 		e2.setValue(0, -5);
		
	 		//Add answers to question
	 		q2.AddAnswer(a2);
			q2.AddAnswer(b2);
			q2.AddAnswer(c2);
			q2.AddAnswer(d2);
			q2.AddAnswer(e2);
		
		
	 	
		//Create a question and a bunch of possible answers for it.
	 	Question q3=new Question("What is the capital of Bulgaria?\n");		
	 		Answer a3= new Answer("Prague");
	 		Answer b3= new Answer("Belgrade");
	 		Answer c3= new Answer("Varna");
	 		Answer d3= new Answer("Sofia");
	 		Answer e3= new Answer("Budapest");
	 		
	 		//Set a value for each answer based on correctness.
	 		a3.setValue(0, -5);
	 		b3.setValue(0, -5);
	 		c3.setValue(0, -5);
	 		d3.setValue(0, 5);
	 		e3.setValue(0, -5);
	 		 
	 		//Add answers to question
	 		q3.AddAnswer(a3);
			q3.AddAnswer(b3);
	 		q3.AddAnswer(c3);
	 		q3.AddAnswer(d3);
	 		q3.AddAnswer(e3);

		//Create a question and a bunch of possible answers for it.
	 	Question q4=new Question("What is the capital of the Netherlands\n");		
		 	Answer a4= new Answer("Amsterdam");
		 	Answer b4= new Answer("Brussels");
		 	Answer c4= new Answer("Holland");
		 	Answer d4= new Answer("The Hague");
		 	Answer e4= new Answer("Hannover");
	 		
		 	//Set a value for each answer based on correctness.
		 	a4.setValue(0, 5);
		 	b4.setValue(0, -5);
		 	c4.setValue(0, -5);
		 	d4.setValue(0, -5);
		 	e4.setValue(0, -5);
	 		 
		 	//Add answers to question
			q4.AddAnswer(a4);
			q4.AddAnswer(b4);
			q4.AddAnswer(c4);
			q4.AddAnswer(d4);
			q4.AddAnswer(e4);
		
		//Create a question and a bunch of possible answers for it.
		Question q5=new Question("What is the capital of the Norway\n");		
		 	Answer a5= new Answer("Copenhagen");
		 	Answer b5= new Answer("Oslo");
		 	Answer c5= new Answer("Stockholm");
		 	Answer d5= new Answer("Bergen");
		 	Answer e5= new Answer("Nynorsk");
	 		
		 	//Set a value for each answer based on correctness.
		 	a5.setValue(0, -5);
		 	b5.setValue(0, 5);
		 	c5.setValue(0, -5);
		 	d5.setValue(0, -5);
		 	e5.setValue(0, -5);
	 		
		 	//Add answers to question
			q5.AddAnswer(a5);
			q5.AddAnswer(b5);
			q5.AddAnswer(c5);
			q5.AddAnswer(d5);
			q5.AddAnswer(e5);
	 
		//Add questions to the exam.
		ex1.AddQuestion(q1);
		ex1.AddQuestion(q2);
		ex1.AddQuestion(q3);
		ex1.AddQuestion(q4);
		ex1.AddQuestion(q5);
		
		//print the exam
		ex1.print();
		
		//Reorder the questions
		ex1.reorderQuestions();		
		
		//Reorder the answers
		q1.reorderAnswers();
		q2.reorderAnswers();
		q3.reorderAnswers();
		q4.reorderAnswers();
		q5.reorderAnswers();
		
		//Print the reordered exam
		System.out.println("The reorderd exam (both Questions and Answers) is; \n");
		
		ex1.print();
		
		Scanner in = new Scanner(System.in);
		int num;
		
		//Change names of the newly reshuffled questions so the input
		//the user provides matches the order the questions are printed in.
		
		q1=ex1.getQuestion(0);
		q2=ex1.getQuestion(1);
		q3=ex1.getQuestion(2);
		q4=ex1.getQuestion(3);
		q5=ex1.getQuestion(4);
		
		//Ask for user input to answer each of the 5 questions
		num = in.nextInt();	
		q1.selectAnswer(num);
		num = in.nextInt();
		q2.selectAnswer(num);
		num = in.nextInt();
	    q3.selectAnswer(num);
	    num = in.nextInt();
	    q4.selectAnswer(num);
	    num = in.nextInt();
	    q5.selectAnswer(num);
	    
	    in.close();

		
	    //Once all questions are answered the exam is graded.
	    //This will work even if a question is not answered
	    //Than the value will just be 0.
	    //However that requires manually disabling the selection for this answer above.
		System.out.printf("Your total score on the exam is %f", ex1.getValue());
		System.out.println("\n");
		
		//Print the score you got for each question
		 for (int i = 0; i < 5; i++) {
				double val= ex1.getQuestion(i).getValue();				
				System.out.println("\n-------------------------------------");
				System.out.printf("For Question %d you got %f", i+1, val);
				System.out.println("\n-------------------------------------");
			 }
			
		
	}

}

