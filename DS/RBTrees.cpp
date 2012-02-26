rb_insert( Tree T, node x )
 {
    /* Insert in the tree in the usual way */
    tree_insert( T, x );
    /* Now restore the red-black property */
    x->colour = red;
    while ( (x != T->root) && (x->parent->colour == red) ) 
    {
       if ( x->parent == x->parent->parent->left ) 
       {
           /* If x's parent is a left, y is x's right 'uncle' */
           y = x->parent->parent->right;
           if ( y->colour == red ) 
           {
               /* case 1 - change the colours */
               x->parent->colour = black;
               y->colour = black;
               x->parent->parent->colour = red;
               /* Move x up the tree */
               x = x->parent->parent;
               }
           else 
           {
               /* y is a black node */
               if ( x == x->parent->right ) 
               {
                   /* and x is to the right */ 
                   /* case 2 - move x up and rotate */
                   x = x->parent;
                   left_rotate( T, x );
                   }
               /* case 3 - x is left child*/
               x->parent->colour = black;
               x->parent->parent->colour = red;
               right_rotate( T, x->parent->parent );
               }
           }
       else {
            /*parent of x is a right child */
            y = x->parent->parent->left;
           if ( y->colour == red ) 
           {
               /* case 1 - change the colours */
               x->parent->colour = black;
               y->colour = black;
               x->parent->parent->colour = red;
               /* Move x up the tree */
               x = x->parent->parent;
           }
           else 
           {
               /* y is a black node */
               if ( x == x->parent->left ) 
               {
                   /* and x is to the left */ 
                   /* case 2 - move x up and rotate */
                   x = x->parent;
                   right_rotate( T, x );
               }
               /* case 3 x is a right child*/
               x->parent->colour = black;
               x->parent->parent->colour = red;
               left_rotate( T, x->parent->parent );
            }
          }
       }
    /* Colour the root black */
    T->root->colour = black;
}
       
