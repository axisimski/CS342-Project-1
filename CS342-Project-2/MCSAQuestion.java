

import java.util.Collections;
import java.util.Scanner;

public class MCSAQuestion extends MCQuestion {

	//Constructor
	public MCSAQuestion(String text, double maxValue) {
		super(text, maxValue);
	}
	
	//------------------------------------------------------------------------------

	//Sets the right answer to an answer object (Usually given by the students)
	void setRightAnswer(Answer ans) {
	
		this.rightAnswer = ans;
	}
	
	//------------------------------------------------------------------------------

	
	//Creates a new answer object
 	public Answer getNewAnswer() {
	
		System.out.println("Enter answer.\n");
		
		Scanner Utext = new Scanner(System.in);
		String ansU = Utext.nextLine();
		
		System.out.println("Enter the value of the answer.\n");
		
		Scanner cre = new Scanner(System.in);
		double credit = cre.nextDouble();
		
		MCSAAnswer ans = new MCSAAnswer(ansU, credit);
		answers.add(ans);
		
		Utext.close();
		cre.close();
		
		return ans;
	}

	//------------------------------------------------------------------------------

 	//Creates a new answer object
 	
	public Answer getNewAnswer(String text) {
		
		MCSAAnswer ans = new MCSAAnswer(text, maxValue);
		answers.add(ans);
		return ans;
	}

	//------------------------------------------------------------------------------

	//Creates a new answer object

	public Answer getNewAnswer(String text, double creditIfSelected) {
		
		MCSAAnswer ans = new MCSAAnswer(text, creditIfSelected);
		answers.add(ans);
		return ans;
	}

	//------------------------------------------------------------------------------

	//Get the answer from student and set the student answer to it.
	public Answer getAnswerFromStudent() {
		
		System.out.println("Please enter your answer: \n");
		
		Scanner input = new Scanner(System.in);
		
		int stdAns = input.nextInt();
		
		studentAnswer = answers.get(stdAns-1);		
 		
	 	return studentAnswer;
	 	
	 	
	}

	//------------------------------------------------------------------------------

	//Get the value of the question. If the student answer and the right answer are the same get full credit
	//Else return 0 (0 points)
	public double getValue() {
		
		if(rightAnswer.getText()==studentAnswer.getText())			
		{
			return rightAnswer.getCredit(rightAnswer);
		}
		
					
		return 0;
		
	}
	
	//------------------------------------------------------------------------------

	//Print the question and the answers associated with the question
	public void print() {
		
		System.out.printf("%s\n", text);

		
		for (int i=0;i<answers.size();i++) {			
		
            answers.get(i).print();
            
            System.out.println("\n");
         
		}
	}
	
	//------------------------------------------------------------------------------

	//Reorder the answers by shuffling the answers array
	public void reorderAnswers() {
		
		Collections.shuffle(answers);
	}

	//------------------------------------------------------------------------------
	
	//Add an answer to the question
	public void addAnswer(MCAnswer Ans) {
	
		answers.add(Ans);
	}
}





















