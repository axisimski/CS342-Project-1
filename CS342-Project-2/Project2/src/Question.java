import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

//Alexander Simeonovski
//asimeono


public abstract class Question{
	
	protected String text;
	protected Answer rightAnswer;
	protected Answer studentAnswer;
	protected Double maxValue;
	
	protected Question(String text, double maxValue) {		
        System.out.println("foo");
	};
	
	abstract void print();		
 	
	abstract void setRightAnswer(Answer ans);
	
	abstract Answer getNewAnswer();
	
	abstract Answer getAnswerFromStudent();
	
	abstract Double getValue(); 
}

//==========================================================================================

class  MCQuestion extends Question {
	
	protected ArrayList<MCAnswer> anslist=new ArrayList<MCAnswer>();

	
	protected MCQuestion(String n, double maxValue) {
		super(n, maxValue);
		// TODO Auto-generated constructor stub
	}


	
	void print() {
		System.out.println(text);
		
	}
	
	void addAnswer(MCAnswer a) {
		anslist.add(a);
	}
	
	void reorderAnswers() {
		Collections.shuffle(anslist, new Random());
	}


	void setRightAnswer(Answer ans) {
		
		rightAnswer=ans;
		
	}


	Answer getNewAnswer() {
				
		Answer Ans = null;
		return Ans; 
	}


	
	Answer getAnswerFromStudent() {
 
		
		Answer Ans = null;
		return Ans; 
	 //Implement Scanner
		
	}


	Double getValue() {
		
		if(studentAnswer==rightAnswer) {
			return 5.0;
		}
		else return 0.0;
	}




}

//==========================================================================================

class  MCSAQuestion extends MCQuestion{

	protected MCSAQuestion(String n, double maxValue) {
		super(n, maxValue);
		 
	}
	
	Answer getNewAnswer() {
		
		Answer Ans = null;
		return Ans; 
	}
	
	Answer getNewAnswer(String text) {
		
		Answer Ans = null;
		return Ans;  
	}
	
	Answer getNewAnswer(String text, double creditIfSelected) {
		
		Answer Ans = null;
		return Ans;  
	}
	
	Answer getAnswerFromStudent()
	{
		Answer Ans = null;
		
		return Ans;  		
	}
	


	Double getValue() {
		
		if(studentAnswer==rightAnswer) {
			return 5.0;
		}
		else return 0.0;
	}
	
} 

//==========================================================================================


class  SAQuestion extends Question{

	
	protected ArrayList<MCAnswer> anslist=new ArrayList<MCAnswer>();

	
	protected SAQuestion(String n, double maxValue) {
		super(n, maxValue);
		// TODO Auto-generated constructor stub
	}


	
	void print() {
		System.out.println(text);
		
	}



	@Override
	void setRightAnswer(Answer ans) {
		// TODO Auto-generated method stub
		
	}



	@Override
	Answer getNewAnswer() {
		// TODO Auto-generated method stub
		return null;
	}



	@Override
	Answer getAnswerFromStudent() {
		// TODO Auto-generated method stub
		return null;
	}



	@Override
	Double getValue() {
		// TODO Auto-generated method stub
		return null;
	}

	
	
}
