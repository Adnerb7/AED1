//Exercício 4.6.3 do Feofiloff que pede uma função para remover de uma lista encadeada todos os elementos que contém x 

void RemoveX(int x, celula *lst) {
    celula *p, *q;
    p = lst;
    q = lst->seg;

    while (q != NULL) {
        if (q->conteudo == x) {
            p->seg = q->seg;
            free(q);
            q = p->seg;
        } else {
            p = q;
            q = q->seg;
        }
    }
}
