import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

//Alexander Simeonovski
//asimeono


//The Exam class represents a gradable collection of Questions

public class Exam {
	
	//Private string for the header and an array list (qlist) for the 
	//list of questions which make up the exam.
	
	private	String header=" ";
	private	ArrayList<Question> qlist=new ArrayList<Question>();
	
	//Constractor for the exam. Takes a string for the header and prints it.
	Exam(String a) {		
		setHeader(a);
		System.out.println(a);
	}
	
	//Adds a question to the exam by putting it in qlist.
	void AddQuestion(Question q) {		
		qlist.add(q);
	}
	
	//Prints the exam by looping trough qlist. 
	void print() {		
		 for (int i = 0; i < qlist.size(); i++) {
			  qlist.get(i).print(i+1);
			  System.out.println("\n");
		 }
	}	
	
	//Shuffles the exam questions by shuffling qlist.
	void reorderQuestions() {
		Collections.shuffle(qlist, new Random());
	}
	
	//Returns the grade (total points earned), by adding up the values of each question.
	double getValue() {
		double value=0;
		 for (int i = 0; i < qlist.size(); i++) {
			 value=value+ qlist.get(i).getValue();
		 }
		 return value;
	}
	
	
	//Returns ( a reference to ) the question in the given position within the exam
	Question getQuestion( int position ) {
		
		return qlist.get(position);
	}

	/**
	 * @return the header
	 */
	public String getHeader() {
		return header;
	}

	/**
	 * @param header the header to set
	 */
	public void setHeader(String header) {
		this.header = header;
	}  

}
