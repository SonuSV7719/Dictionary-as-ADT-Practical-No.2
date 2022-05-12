#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

class Node
{
public:
	int key;
	string values;
	Node *link;
	Node(int _key);
	Node(string values);
	Node();
};

Node::Node()
{
	link = NULL;
}

Node::Node(string _values)
{
	values = _values;
	link = NULL;
}

Node::Node(int _key)
{
	key = _key;
	link = NULL;
}

class Dictionary
{
public:
	Node **dic = new Node *[MAX];
	Dictionary();
	void push(int key);
	void insert_values(int key, string value);
	void print_values(int key);
	int hash_code(int key);
	bool serach_key(int key);
    void display();
};

void Dictionary::display()
{
    for(int i = 0; i<MAX; i++)
    {
        Node* traverse, *temp;
        if(dic[i] != NULL)
        {
            temp = dic[i]->link;
		    traverse = temp;
		    cout << "Values of " << i << " is : ";
		    while (traverse->link != NULL)
		    {
			    cout << traverse->values << "->";
			    traverse = traverse->link;
		    }
		    if (traverse->link == NULL)
		    {
			    cout << traverse->values << "->"
				     << "NULL"<<endl;
		    }
            }
    }
}

Dictionary::Dictionary()
{
	for (int i = 0; i < MAX; ++i)
	{
		dic[i] = NULL;
	}
}

int Dictionary::hash_code(int key)
{
	return (key % MAX);
}

void Dictionary::push(int key)
{
	int index = hash_code(key);
	Node *key_node = new Node(key);
	dic[index] = key_node;
	string yes_no;
	int cnt = 0;
	do
	{
		cnt++;
		string value;
		cout << "Enter Values of " << key << " : ";
		cin >> value;
		Node *value_head;
		if (cnt == 1)
		{
			Node *values_node = new Node();
			values_node->values = value;
			key_node->link = values_node;
			value_head = values_node;
		}
		else
		{
			Node *temp = value_head;
			while (temp->link != NULL)
			{
				temp = temp->link;
			}
			Node *next_value = new Node();
			next_value->values = value;
			temp->link = next_value;
		}

		cout << "Do You want to enter more values if yes then press 'y': ";
		cin >> yes_no;
	} while (yes_no == "y" or yes_no == "Y");
}

void Dictionary::insert_values(int key, string value)
{
	int index = hash_code(key);
	if (serach_key(key) == true)
	{
		Node *new_value = new Node();
		Node *temp;
		temp = dic[index]->link;
		Node *traverse_node;
		traverse_node = temp;
		while (traverse_node->link != NULL)
		{
			traverse_node = traverse_node->link;
		}
		new_value->values = value;
		traverse_node->link = new_value;
	}
	else
	{
		Node* _key = new Node(key);
		Node* _value = new Node();
		dic[index] = _key;
		dic[index]->link = _value;
		_value->values = value;
	}
	
}

bool Dictionary::serach_key(int key)
{
	int index = hash_code(key);
	if (dic[index] != NULL)
		return true;
	else
		return false;
}

void Dictionary::print_values(int key)
{
	int index = hash_code(key);
	Node *traverse, *temp;
	if (serach_key(key) == true)
	{
		temp = dic[index]->link;
		traverse = temp;
		cout << "Values of " << key << " is : ";
		while (traverse->link != NULL)
		{
			cout << traverse->values << "->";
			traverse = traverse->link;
		}
		if (traverse->link == NULL)
		{
			cout << traverse->values << "->"
				 << "NULL"<<endl;
		}
	}
	else
	{
		cout << "Entered Key is Not Found";
	}
}



int main()
{
	Dictionary dic1;
    int n, key;
	do
    {
        int choice;
        cout<<"*********************** Menu **************************"<<endl;
        cout<<"1.Create\n2.Display\n3.Search\n4.Exit\nEnter your choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            /* code */
            cout<<"Enter how many elements you want to enter in dictionary: ";
            cin>>n;
            for(int i = 0; i<n;i++)
            {
                string value;
                cout<<"Enter key(int integer): ";
                cin>>key;
                cout<<"Enter value(string values): ";
                cin>>value;
                dic1.insert_values(key, value);
            }
            break;
        case 2:
            /* code */
            cout<<"**************** Data In Dectionary *******************"<<endl;
            dic1.display();
            break;
        case 3:
            /* code */
            cout<<"Enter Key to search: ";
            cin>>key;
            if (dic1.serach_key(key))
                cout<<key<<" Found!!"<<endl;
            else
                cout<<key<<" Not found!!"<<endl;
            break;
        case 4:
            /* code */
            exit(0);
            break;
        
        default:
            cout<<"Plz Try again you enterd wrong option!!"<<endl;
            break;
        }
        


    }while(1);
	return 0;
}
