import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

//Alexander Simeonovski
//asimeono



public class Exam {

	private	String header=" ";
	private	ArrayList<Question> qlist=new ArrayList<Question>();
	
	Exam(String a) {		
		setHeader(a);
		System.out.println(a);
	}
	
	void AddQuestion(Question q) {		
		qlist.add(q);
	}
	
	void print() {		
		 for (int i = 0; i < qlist.size(); i++) {
		      System.out.printf("%d) ",i+1);
			  qlist.get(i).print();
			  System.out.println("\n");
		 }
	}	
	
	void reorderQuestions() {
		Collections.shuffle(qlist, new Random());
	}
	
	double getValue() {
		double value=0;
		 for (int i = 0; i < qlist.size(); i++) {
			 value=value+ qlist.get(i).getValue();
		 }
		 return value;
	}
	
	
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
