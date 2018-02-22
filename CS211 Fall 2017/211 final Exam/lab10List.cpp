#include "lab10List.h"


MyLNode::MyLNode (int v1)
{
  elem = v1;
  next = NULL;
}
  
MyLNode::MyLNode (int v1, MyLNode* n)
{
  elem = v1;
  next = n;
}

void MyLNode::setElem (int e)
{
  elem = e;
}

int MyLNode::getElem ()
{
  return elem;
}

void MyLNode::setNext (MyLNode* n)
{
  next = n;
}

MyLNode* MyLNode::getNext()
{
  return next;
}

MyList::MyList()
{
  head = NULL;
}
 
void MyList::show()
{
	MyLNode* tmp = head;
	
	while(tmp!=NULL){
		printf("%d\n", tmp->getElem());
		tmp=tmp->getNext();	
	}


}

void MyList::insert (int v1)
{
  MyLNode* tmp = new MyLNode (v1);
  
   tmp->setNext (head);
  head = tmp;
}

void MyList::remove (int v1)
{   

 MyLNode* curr = head;
 MyLNode* prev = NULL;
 while (( curr != NULL) && ( curr->getElem() != v1 ))
 {
 prev = curr;
 curr = curr->getNext();
 }
 if ( curr == NULL )
 return;
 if ( prev == NULL )
 head = curr->getNext();
 else
 prev->setNext ( curr->getNext() );
 delete curr;
	    
    
  
}

void MyList::insertOrder (int v1)
{
	
	MyLNode* tmp = new MyLNode (v1);
 	MyLNode* curr = head;
	 MyLNode* prev = NULL;
 	while (( curr != NULL) && ( curr->getElem() < v1 ))
 	{
 		prev = curr;
 		curr = curr->getNext();
 	}
 	tmp->setNext( curr);
 	if ( prev == NULL )
 	head = tmp;
 	else
 	prev->setNext ( tmp );

}


int MyList::pop ()
{
	MyLNode* tmp = head;
	
	if(head==NULL){
		return 0;
	}
	
 	head=head->getNext();
	delete(tmp); 
  
}


int MyList::getLength(){
	
	MyLNode* tmp = head;
	int x;
	while(tmp!=NULL){
		tmp=tmp->getNext();
		x++;
	}
		
	return x;	
	
} 

int MyList::getNth (int n)
{
	MyLNode* tmp = head;
	int x=1;

	for(x=1;x<n;x++){
	
		tmp=tmp->getNext();
		
	}	
	return tmp->getElem();
  
}




int MyList::exists (int n)
{
    MyLNode* tmp = head;
 
	
	while(tmp!=NULL){
		if(tmp->getElem()==n){
			return 1;
		}
		tmp=tmp->getNext();
		
	}
	
	return 0;
  
}

int MyList::isEmpty ()
{
 if(head==NULL){
		return 1;
	}
	
	else return 0;
  
}

int MyList::top ()
{
 	 MyLNode* tmp = head; 
	
	if(tmp==NULL){
		return 0;
	}
	else
	return tmp->getElem();
  
}

void MyList::removeAll()
 {
MyLNode* tmp;
while ( head != NULL )
{
 tmp = head;
 head = head->getNext();
 delete tmp;
}
}




