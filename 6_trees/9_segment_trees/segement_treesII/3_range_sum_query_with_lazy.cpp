// segment tree example - with lazy propagation | practice problem
// range sum query
// a = [1,2,2,3,0,4,3,6,9,10]

// Query of the type sum (a,l,r)

//------------
int getSum(node,l,r)
{
    if the range of the node is within l and r
    return value in the node
    else if the range of the node is completely outside l and r

    else
    leftsum = getsum(node's left child , l, r)
    rightsum= getsum(node's right child , l, r)
    return leftsum + rightsum
}




// -------------------