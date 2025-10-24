#Exercicío 4.6.1 da apostila do Feofiloff que pede uma versão da função BuscaERemove para lista encadeada sem cabeça

void BuscaERemove(int x, celula **lst) {
    celula *p, *q;

    if (*lst == NULL)
        return;

    if ((*lst)->conteudo == x) {
        q = *lst;
        *lst = q->seg;
        free(q);
        return;
    }
    p = *lst;
    q = p->seg;

    while (q != NULL && q->conteudo != x) {
        p = q;
        q = q->seg;
    }
    if (q != NULL) {
        p->seg = q->seg;
        free(q);
    }
}
