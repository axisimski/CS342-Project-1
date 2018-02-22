

import java.util.Scanner;
public class SAQuestion extends Question {
	public SAQuestion(String text, double maxValue) {
		super(text, maxValue);
	}

	//Input an answer by scanning for it and putting it in the question array
	public Answer getNewAnswer() {
		System.out.println("Please enter a short answer.\n");
		Scanner inp = new Scanner(System.in);
		String ansU = inp.nextLine();
		SAAnswer ans = new SAAnswer(ansU);
		return ans;
	}

	//Scan for student answer and set it to the studentAnswer
	public Answer getAnswerFromStudent() {
		
		System.out.println("Please enter your answer: \n");

		Scanner inp = new Scanner(System.in);
		String studentAns = inp.nextLine();
		this.studentAnswer = new SAAnswer(studentAns);
        return this.studentAnswer;        
	}

	//Return the value associated with the question
	public double getValue() {
		
		
		if(studentAnswer.getText().equals(rightAnswer.getText())) {			
			
			return  maxValue;
		}
		
		else
        return 0;
	}

	//Set the right answer
	@Override
	void setRightAnswer(Answer ans) {
		
		rightAnswer=ans;
		
	}
	
	
	//print
	@Override
	public void print() {
		
		System.out.printf("%s\n", text);

	
	}
}
