
import java.util.ArrayList;
import java.util.Collections;

public abstract class MCQuestion extends Question {
	
	
	//Arraylist of McAnswers
	protected ArrayList<MCAnswer> answers;
	
	
	//Constructor
	MCQuestion(String text, double maxValue) {
		super(text, maxValue);
		answers = new ArrayList<MCAnswer>();
	}
		
	//Print fn()
	abstract public void print();

	//For adding answers to MC questions
	public abstract void addAnswer(MCAnswer Ans);

	//for reordering answers
	abstract public void reorderAnswers();

	
}