bool is_bst(Node *root)
{
    static Node *prev = NULL;

    if (root != NULL) {
        if (!is_bst(root->left)) return false;
        if (prev != NULL && root->data <= prev->data) return false;

        prev = root;
        return is_bst(root->right);
    }

    return true;
}
