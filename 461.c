void BuscaERemove(int x, celula **lst) {
    celula *p, *q;

    if (*lst == NULL)
        return;

    if ((*lst)->conteúdo == x) {
        q = *lst;
        *lst = q->seg;
        free(q);
        return;
    }
    p = *lst;
    q = p->seg;

    while (q != NULL && q->conteúdo != x) {
        p = q;
        q = q->seg;
    }
    if (q != NULL) {
        p->seg = q->seg;
        free(q);
    }
}
