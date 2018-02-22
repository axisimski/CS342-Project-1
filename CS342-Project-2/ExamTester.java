

public class ExamTester {
	public static void main(String args[]) {
		
	
		/*-The questions will be printed along with the possible answers
-For question 1 and 2 if the answer is a, the user inputs 1, if b 2, if c 3...ENTER.
-For questions 3 and 4 you have to input a string Answer immidiattly after entering theanswer to question 2 (You don't get another prompt).
-The answers are 3 ENTER, 0 ENTER Paris ENTER, Moscow ENTER
-The questions and answers will be shuffled printed again.
-The exam will be graded and your score will be printed.*/
		
		//Create an exam with at least two kinds of questions (2 SA and 2 MCSA Questions)
		
		Exam ex1 = new Exam("\nFor the first 2 questions select a correct answer for 5 points 1 for a, 2 for b...5 for d.\n\n"  + 
				"For the second two type in your answers\n\n\n");

		
		MCSAQuestion q1=new MCSAQuestion("What is the capital of Germany?\n", 1);		
		q1.getNewAnswer("Munich", 0);
 		q1.getNewAnswer("Rome", 0);
 		q1.getNewAnswer("Frankfurt", 0); 	
 		q1.getNewAnswer("Berlin", 0); 
 		q1.getNewAnswer("Hamburg", 0); 
 		MCSAAnswer ans=new MCSAAnswer("Berlin", 1);
 		q1.setRightAnswer(ans);
 		
 		
 		MCSAQuestion q2=new MCSAQuestion("What is the capital of Bulgaria?\n", 1);		
		q2.getNewAnswer("Sofia", 0);
 		q2.getNewAnswer("Skopje", 0);
 		q2.getNewAnswer("Belgrade", 0);
 		q2.getNewAnswer("Bucharest", 0);
 		q2.getNewAnswer("Sarajevo", 0); 		
 		MCSAAnswer ans2=new MCSAAnswer("Sofia", 1);
 		q2.setRightAnswer(ans2);
 		
  
 		SAQuestion q3=new SAQuestion("What is the capital of France (5 points)", 5); 		
 		SAAnswer ans3=new SAAnswer("Paris"); 		
 		q3.setRightAnswer(ans3); 	
 		
 		SAQuestion q4=new SAQuestion("What is the capital of Russia (10 points)", 10); 		
 		SAAnswer ans4=new SAAnswer("Moscow"); 		
 		q4.setRightAnswer(ans4); 
 		
 		ex1.addQuestion(q1);
 		ex1.addQuestion(q2);
 	 	ex1.addQuestion(q3);
 	 	ex1.addQuestion(q4);
 		
 	 	//Step 2 print the exam
 	 	ex1.print();
 		
 		System.out.println("\nReordering Questions and Multiple choice answers!\n");
 	 	
 		//Reorder the questions
 		ex1.reorderQuestions(); 
 		
 		//(-999 to reorder all MCQuestion answers
 		ex1.reorderMCAnswers(-999);
 		
 		
 		//Print the exam again
 		ex1.print();

 			
 		//Get Student Answers
 		ex1.getAnswerFromStudent(0);
 		ex1.getAnswerFromStudent(1);
 		ex1.getAnswerFromStudent(2);
 		ex1.getAnswerFromStudent(3);
 	
 	
 		
 
 		//Grade the exam
		System.out.println("Grading exam...\n");
		System.out.printf("Score: %f\n", ex1.getValue());
		
		//Print the value for each question. Since no Exam.getQuestion(i) is permitted it is done manually
			 
		ex1.reportQuestionValues();
			 
	}
}











