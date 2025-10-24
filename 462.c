//Exercício 4.6.2 da apostila do Feofiloff que pede uma versão da função BuscaEInsere para listas encadeadas sem cabeça

void BuscaEInsere(int y, celula **lst) {
    celula *p, *q, *nova;

    nova = malloc(sizeof(celula));
    if (nova == NULL) {
        printf("Erro.\n");
        return;
    }

    nova->conteudo = y;
    if (*lst == NULL) {
        nova->seg = NULL;
        *lst = nova;
        return;
    }

    p = NULL;
    q = *lst;
    while (q != NULL && q->conteudo < y) {
        p = q;
        q = q->seg;
    }
    if (p == NULL) {
        nova->seg = *lst;
        *lst = nova;
    }
    else {
        nova->seg = q;
        p->seg = nova;
    }
}
