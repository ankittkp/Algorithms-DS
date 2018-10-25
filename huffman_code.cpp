#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char c;
	int frequency;
	Node *left,*right;
};
struct Node* getNode(char ch, int freq, Node *left,Node *right)
{
	struct Node* node=new Node();
	node->c=ch;
	node->frequency=freq;
	node->left=left;
	node->right=right;

	return node;
}
struct comp
{
	bool operator()(Node *l,Node *r)
	{
		return l->frequency > r->frequency;
	}
};
void decode(Node *root, int &index ,string str)
{
	if(root==NULL)
	{
		return;
	}
	if(!root->left && !root->right)
	{
		cout<<root->c;
		return;
	}
	index++;
	if(str[index]=='0')
	{
		decode(root->left,index,str);
	}
	else
	{
		decode(root->right,index,str);
	}
}
void encode(Node *root,string str,unordered_map<char,string>&huffmancode)
{
	if(root==NULL)
	{
		return;
	}
	if(!root->left && !root->right)
	{
		huffmancode[root->c]=str;
	}
	encode(root->left,str+"0",huffmancode);
	encode(root->right,str+"1",huffmancode);
}
void getfrequency(string s)
{
	unordered_map<char,int>freq;
	unordered_map<char,string>huffmancode;
	for(int i=0;i<s.size();i++)
	{
		freq[s[i]]++;
	}
	
	for(auto it:freq)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
	priority_queue<Node*,vector<Node*>,comp> pq;
	for(auto it:freq)
	{
		pq.push(getNode(it.first,it.second,NULL,NULL));
	}
	while(pq.size()!=1)
	{
		Node* left= pq.top(); pq.pop();
		Node* right=pq.top(); pq.pop();
		cout<<left->c<<endl;
		cout<<right->c<<endl;
		int sum = left->frequency + right->frequency;
		cout<<"sum  : "<<sum<<endl;
		pq.push(getNode('\0',sum,left,right));
	}
	Node* root=pq.top();
	encode(root,"",huffmancode);
	cout<<"huffmancodes are :"<<endl;
	for(auto it:huffmancode)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
	string str="";
	for(char ch:s)
	{
		str+=huffmancode[ch];
	}
	cout<<"encoded string are :"<<str<<endl;
	cout<<"decoded string are :"<<endl;
	int index=-1;
	while(index<(int)str.size()-2)
	{
		decode(root,index,str);
	}

}
int main()
{
	string s;
	cin>>s;
	getfrequency(s);
}