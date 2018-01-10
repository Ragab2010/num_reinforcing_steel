#include "linked_list.h"


	list::list(){
		fraction=0;
		number_of_Iron=0;
		head =NULL;
		head_fraction=NULL;
		end=NULL;
		end_fraction=NULL;
		size=NULL;
		size_fraction=NULL;
	}
	

	list::list(int number , int length):size(0),size_fraction(0){
		fraction=0;
		number_of_Iron=0;
		head =NULL;
		head_fraction=NULL;
		end=NULL;
		end_fraction=NULL;
		size=NULL;
		size_fraction=NULL;
		/*---------------------*/
		head = new Node;
		head->next =NULL;
		if(!head)
			cout<<"there is no memory to allocate node"<<endl;
		end=head;
		head->number =number;
		head->length =length;
		size++;
	}
	int list::insert(int number , int length){
		Node *pn = new Node;
		pn->next =NULL;
		if(!pn)
			return 0;
		if(!size){
			head = pn;
		}else{
			end->next = pn;
		}
		end = pn;
		pn->number=number;
		pn->length=length;
		size++;
		return 1;
	}
	int list::insert_fraction(int length){
		Node *pn = new Node;
		if(!pn)
			return 0;	
		pn->next =NULL;
		if(!size_fraction){
			head_fraction = pn;
		}else{
			end_fraction->next = pn;
		}
		end_fraction = pn;
		pn->number=1;
		pn->length=length;
		size_fraction++;
		return 1;
	}
	int list::travest(){
		Node *pn= head;
//		while(pn){
//			cout<<"the number is :"<<pn->number<<endl;
//			cout<<"the length is :"<<pn->length<<endl;
//			cout<<"-----------------"<<endl;
//			pn=pn->next;
//		}
		pn=head_fraction;
		while(pn){
			cout<<"One fraction Bars equal :"<<pn->length<<"Meter"<<endl;
			cout<<"-------------------------"<<endl;
			pn=pn->next;
		}
		return 1;
	}
	
	list::~list(){
	Node *pn= head;
		while(pn){
			pn=head->next;
			delete [] head;
			head=pn;
		}
		pn= head_fraction;
		while(pn){
			pn=head_fraction->next;
			delete [] head_fraction;
			head_fraction=pn;
		}
	}
	int list::remove(Node *pn ,Node *back_pn){
		if(size_fraction == 1){		
			head_fraction =pn->next;
			delete [] pn;
		}
		else if(head_fraction == back_pn){
			head_fraction =pn->next;
			delete [] pn;
		}else{
			back_pn->next =pn->next;
			delete [] pn;
		}
		size_fraction--;
		return 1;
	}
	
	int list::search(int length ){
		int current_length=0 ;
		Node *pn= head_fraction;
		Node *back=head_fraction ;
		if(!size_fraction)
			return 0;
		while(pn){
			if((pn->length)  >= length){
				current_length = pn->length;
				remove(pn,back);
				return current_length;
			}	
			back=pn;
			pn=pn->next	;
		}
		return  0;
	}
	int list::calc(){

		Node *pn=head;
		number_of_Iron=0 ;
		do{
			while(pn->number){
				fraction = search(pn->length);
				if(!fraction){
					number_of_Iron++;
					fraction =IRON;
				}
				while(pn->number && (fraction >= pn->length) ){
					fraction = fraction - pn->length;
					pn->number--;
				}
					if(fraction){
						insert_fraction(fraction);		
					}
			}

			pn=pn->next;
			
		}while(pn);
		return 1;
	}
	int list::show(){
		cout<<"---------**************---------"<<endl;
		cout<<"-------------******-------------"<<endl;
		cout<<"Number of Iron :"<<number_of_Iron<<endl;
		cout<<"------------------"<<endl;
		travest();
		return 1;
	}

	int Read( list & pn){
	char check;
	int num=0 ,len=0;
	cout<<"Lenth of Rebars =12 meter\nEnter the Lengths by Meter"<<endl;
		do{
			cout<<"Enter the number :";
			cin>>num;
			cout<<"Enter the length :";
			cin>>len;
			pn.insert(num , len);
			cout<<"Do you Want continuo (y/n) :";
			cin>>check;
		}while((check !='n')&&(check !='N'));
		return 1;
	}
	int exit(){
		cout<<"Do you Want exit(y/n)";
		char exit;
		cin>>exit;
		return exit;
	}
