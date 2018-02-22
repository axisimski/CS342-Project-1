

//Abstract class which serves as a blueprint for its child classes

public abstract class Question {
	
	//The question consists of a string (For the question)
	//2 Answers, one is the right answer, the other the student answer
	//They can be compared to determine the amount of credit the student earns.
	//The max value holds the value of the question
	protected String text;
	protected Answer rightAnswer;
	protected Answer studentAnswer;
	protected double maxValue;
	
	//Constructor
	protected Question(String text, double maxValue) {
	
		this.text = text;
		this.maxValue = maxValue;
	}

	//Prints the question
	abstract public void print();

	//Sets the right answer
	abstract void setRightAnswer(Answer ans);

	//Get a new answer for the question
	abstract Answer getNewAnswer();
	
	//Get the answer from the student
	abstract Answer getAnswerFromStudent();

	//Get the value of the question
	abstract double getValue();

}

