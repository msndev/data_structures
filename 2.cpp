struct node
{
int data;
node *left,*right;
};

class binaryTree
{
public:
int totalNodesCreated;
node *minimum;
node *head;
int leafSumNodes;

node* createNewNode(int data)
{
node*ptr=new node(); ptr->data=data;
ptr->left=NULL;ptr->right=NULL; return ptr;
}

binaryTree(int data)
{
head = createNewNode(data); totalNodesCreated=0;
minimum = createNewNode(INT_MAX); leafSumNodes=0;
}

int height(node *ptr)
{
if(ptr->left!=NULL) return(1+height(ptr->left));

else

}


void addValues(node *ptr,int data,int a)
{

int h=height(ptr);
// a=totalnodes+2

if(pow(2,h+1)==a)
{
while(h)
{
ptr=ptr->left; h--;
}
ptr->left=createNewNode(data); totalNodesCreated++;
}
else if(h==0)
{
ptr->left=createNewNode(data);

totalNodesCreated++;
}
else if(h==1 && a==pow(2,h)+2)
{
ptr->left->left=createNewNode(data); totalNodesCreated++;
}
else if(h==1)
{


}
else
{

ptr->right=createNewNode(data); totalNodesCreated++;


if(a>=pow(2,h) && a<(pow(2,h)+pow(2,h)/2))
{


}
else
{

}
}
}

addValues(ptr->left,data,a-pow(2,h)/2);


addValues(ptr->right,data,a-pow(2,h));


node* searchTheElement(int data)
{
node *ptr=head; if(ptr==NULL)
cout<<"Binary tree is empty\n";

else
{


int b=1; queue<node*>q; q.push(head); while(!q.empty())
{

node* a = q.front(); q.pop();
if(a->data==data){ b++;
cout<<"Element is found"; return a;
break;
}
if(a->left!=NULL) q.push(a->left);
if(a->right!=NULL) q.push(a->right);
}
if(b==1)
cout<<"Element not found\n";
}
}

void display()
{
queue<node*>q; q.push(head); while(!q.empty())

{
node* a = q.front(); q.pop();
cout<<a->data<<" "; if(a->left!=NULL)
q.push(a->left); if(a->right!=NULL)
q.push(a->right);
}
}

void inorder(node *ptr)
{
if(ptr)
{
inorder(ptr->left); cout<<ptr->data<<" "; inorder(ptr->right);
}
}

void preorder(node *ptr)
{
if(ptr)
{
cout<<ptr->data<<" "; preorder(ptr->left); preorder(ptr->right);
}
}

void postorder(node *ptr)
{
if(ptr)
{
postorder(ptr->left); inorder(ptr->right); cout<<ptr->data<<" ";
}
}

node* findMaximum(node *ptr)
{
if(ptr->right==NULL) return(ptr);
return(findMaximum(ptr->right));
}

node* deleteNode(node* root, int data)
{
if (root == NULL) return root;
if (data != root->data){
root->left = deleteNode(root->left, data); root->right = deleteNode(root->right, data);

}
else
{



if (root->left == NULL)
{

node *temp = root->right; delete(root);
return temp;
}
else if (root->right == NULL)
{
node *temp = root->left; delete(root);
return temp;
}
node* temp = findMaximum(root->left); root->data = temp->data;
root->left = deleteNode(root->left, temp->data);
}
return root;
}

void findMinimum(node *ptr)
{
if(ptr)
{
if(minimum->data > ptr->data) minimum=ptr;
findMinimum(ptr->left); findMinimum(ptr->right);
}
}

void sumOfAllTheLeafNodes(node *ptr)
{
if(ptr)
{
if(ptr->left==NULL && ptr->right==NULL) leafSumNodes+=ptr->data;
sumOfAllTheLeafNodes(ptr->left); sumOfAllTheLeafNodes(ptr->right);
}
}
};
int main()
{
char c='y'; heap h(50); BST bs(6);
binaryTree bt(6); while(c=='y')
{
cout<<"\n	18BCE0559 Sreenitya Mandava\n\n";
cout<<"\n	18BCE0165 HARSHIT GOEL\n\n";
cout<<"1.Insertion\n2.Deletion\n3.InOrder Traverse\n4.PreOrder Traverse\n5.PostOrder Traverse\n";
cout<<"6.Display according the level\n7.Display The Minimum value\n8.Display the sum of all Leaf Nodes\n";
cout<<"\nEnter your choice...\n"; int choice;
cin>>choice; switch(choice)
{
cout<<"\n	18BCE0559 Sreenitya Mandava\n\n";
case 1:
{
cout<<"\nEnter the value\n"; int data;
cin>>data;

bt.addValues(bt.head,data,bt.totalNodesCreated+2);
break;
}
case 2:
{
cout<<"\nEnter the value you want to delete\n"; int data;
cin>>data; bt.head=bt.deleteNode(bt.head,data); break;
}
case 3:
{
bt.inorder(bt.head);

break;
}
case 4:
{
bt.preorder(bt.head); break;
}
case 5:
{
bt.postorder(bt.head); break;
}
case 6:
{
bt.display(); break;
}
case 7:
{
bt.findMinimum(bt.head); cout<<bt.minimum->data; break;
}
case 8:
{
bt.sumOfAllTheLeafNodes(bt.head); cout<<bt.leafSumNodes;
break;
}
}
break;
}

