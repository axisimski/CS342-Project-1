

import java.util.ArrayList;
import java.util.Collections;

public class Exam {
	
	//Arraylist to store the questions 
	//A string to hold the header
	private ArrayList<Question> questions;
	private String text;

	//Constructor//prints the my name, netid and the header.
	public Exam(String text) {
		
		System.out.printf("Alexander Simeonovski\nasimeono\n");
		this.text=text;
		questions = new ArrayList<Question>();
	}

	//--------------------------------------------------------------------------------------------------
	//Prints the exam by looping trough the list of questions
	public void print() {
		
		System.out.printf("%s\n", getText());
		
		 for (int i = 0; i < questions.size(); i++) {
			 
		      System.out.printf("%d) ",i+1); //i+1 since we don't want the questions to start at 0.
		      questions.get(i).print(); //Print the question (and answers)
			  System.out.println("\n"); //Print a new line 
		 }
	}
	
	//--------------------------------------------------------------------------------------------------

	//Add questions to the exam
	public void addQuestion(Question question) {
	
		questions.add(question);
	}
	
	//--------------------------------------------------------------------------------------------------

	//Reorder the questions by shuffling the questions arraylist
	public void reorderQuestions() {
		
		Collections.shuffle(questions);
	}
	
	//--------------------------------------------------------------------------------------------------

	//Reorder the McAnswers 
 	public void reorderMCAnswers(int position) {		 		
		
		//If position is  positive, reorder the questions of the answer at position
		if(Math.signum(position)==1) {
			
			if (questions.get(position) instanceof MCQuestion) {
				
				((MCQuestion) questions.get(position)).reorderAnswers();
			} 
			
			//If not a  MCQuestion
			else 
				System.out.println("Not a  Multiple Choice Question\n");
			
		}
		
		//If position is negative, reorder the answers to all questions
		else if(Math.signum(position)==-1) {
			
			for (int i=0;i<questions.size();i++) {
				
				if (questions.get(i) instanceof MCQuestion)
				{
					Collections.shuffle(((MCQuestion) questions.get(i)).answers);
				}
			}
		}
		
	}
 	
 	
	//--------------------------------------------------------------------------------------------------


 	//Add up the total value of all the questions
	double getValue() {
		
		double value=0;
		
		 for (int i = 0; i < questions.size(); i++) {
			 value=value + questions.get(i).getValue();
		 }
		 
		 return value;
	}
	
	//--------------------------------------------------------------------------------------------------

	//Calls the getAnswerFromStudent at int position in the Question Arrraylist
	public void getAnswerFromStudent(int position) {
	
		questions.get(position).getAnswerFromStudent();
	}
	
	//--------------------------------------------------------------------------------------------------

	//Report the values for individual questions
	public void reportQuestionValues() {
		
		int i = 0;
		
		for (Question examQuestion : questions) {
			System.out.printf(
					"For Question %d you got %f points\n\n", i+1, examQuestion.getValue());
			i++;
		}
		
	}
	
	//--------------------------------------------------------------------------------------------------

	
	//Getter for text
	public String getText() {
		return text;
	}
	
	//--------------------------------------------------------------------------------------------------

	
	//Setter for text
	public void setText(String text) {
		this.text = text;
	}
}

