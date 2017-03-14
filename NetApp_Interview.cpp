/*
int count_left, count_right;

data, left, right, right
*/


struct node_t {
    int val;
    node_t* left;
    node_t* right;
}; 

/* Print Vertical Nodes in an unbalanced binary tree.
                       1
                     2    3
                   4   56   7(+2)
                 8(-3)  
                 
4, 2, 1, 5,6 3, 7
*/

/* Finds left and right max to know the range of values to initialize the hashmap */
void findOffsets(node_t *root, int *max_left, int *max_right, int current_offset)
{
    if(root == null)
        return;    
    if(max_left > current_offset)
        max_left = current_offset;
    if(max_right < current_offset)
        max_right = current_offset;

    // Recursively traverse the whole tree
    findOffsets(root->left, max_left, max_right, current_offset-1);
    findOffsets(root->right, max_left, max_right, current_offset+1);
}

void printVertical(node_t *root)
{

    int count_left = 0,count_right = 0,current = 0;
    std::map<int, std::string> line_map; 
    
 
    findOffsets(root,count_left,count_right,current);
    
    for(int i=count_left;i<=count_right;i++)
    {
       // Empty String
       line_map.insert(i,"");
    }
    
    printVericalLine(*root, 0,line_map);
     
     
    for(std::map<int,std::string>::iterator line = line_map.begin() ; line != line_map.end() ; ++line )
    {
    
        printf("Line:%d => %s\n",line->first,line->second);
    }
    
   
    
    
    /*
    for(int line=count_left;line<=count_right;line++)
    {
        printf("Printing Column %d:", line);
        printVericalLine(*root, line);
    }
    */

}

void printVerticalLine(node_t *root, int current_offset, std::map<int,std::string> &map)
{
    if(root == NULL)
        return;
    /*    
    if(root->offset == offset){
        printf("%d,",root->val);
    }
    */
    
    std::string temp = map.find(current_offset);
    std::string new_val;
    sprintf(new_val, "%s%d,", temp, root->val);
    map.erase(current_offset)
    map.insert(current_offset,new_val);
    
    
    printVerticalLine(root->left,current_offset-1, map);
    printVerticalLine(root->right, current_offset+1, map);

}



