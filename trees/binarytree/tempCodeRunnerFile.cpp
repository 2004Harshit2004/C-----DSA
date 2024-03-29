
    }
};

void print(Node* root,int level){
    if(level==1) cout<<root->val;
    print(root->left,--level);