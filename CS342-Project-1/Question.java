import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

//Alexander Simeonovski
//asimeono

//The Question class represents a textual multiple-choice question

public class Question {
	
	//private variables as specified in the instructions
	//The string q represents a given question.
	//points holds the points the question is worth. The default is 0.
	//Each question stores its answers into an array list.
	
	private String q=" ";
	private double points;
	private ArrayList<Answer> anslist=new ArrayList<Answer>();
	
	//Question constructor. Takes a string for the question and holds the amount of
	//points that it is worth.
	
	Question(String x) {	
		q=x;
		points=0;
	}
	//Ads an answer to the answer array list.
	
	void AddAnswer(Answer a){		
		anslist.add(a);
	}
	
	//Prints questions based on their order. 1) for the first, 2) for the second etc...
	
	void print(int n) {		
		if(n==1) {
			System.out.printf("1) %s\n", q);}
		if(n==2) {
			System.out.printf("2) %s\n", q);}
		if(n==3) {
			System.out.printf("3) %s\n", q);}
		if(n==4) {
			System.out.printf("4) %s\n", q);}
		if(n==5) {
			System.out.printf("5) %s\n", q);}
	
		 for (int i = 0; i < anslist.size(); i++){
			 anslist.get(i).print(i+1);;
		 } 
	}
	
	//Selects an answer for a question (marks it as checked).
	//Since the array list in java starts at 0, but I want the user input 
	//to start at 1, 1 is subtracted from the positions to get the correct
	//index of the question in the array list.
	
	void selectAnswer( int position ) {		
		anslist.get(position-1).setSelected(true);
		points=anslist.get(position-1).getValue();
	}
	
	//If one chooses to unselect an answer this restores it to the default
	//It restores the selected value to false and points to 0.
	
	void unselectAnswer( int position ) {		
		anslist.get(position).setSelected(false);
		points=0;
	}
	
	//Returns the points for each question
	
	double getValue() {
		return points;
	}
	
	//Reorders the Answers to each question by shuffling the array list.
	
	void reorderAnswers() {
		Collections.shuffle(anslist, new Random());
	}

}
