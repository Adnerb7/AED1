//Exercicio 4.6.4 do Feofiloff que pede uma função para remover o conteúdo mínimo de uma célula encadeada ((versão iterativa))

void RemoveMin(celula **lst) {
    if (*lst == NULL) return;

    celula *p = *lst;
    celula *ant_min = NULL;
    celula *min = *lst;
    celula *ant = NULL;

    while (p != NULL) {
        if (p->conteudo < min->conteudo) {
            min = p;
            ant_min = ant;
        }
        ant = p;
        p = p->seg;
    }

    if (ant_min == NULL) {
        *lst = min->seg;
    } else {
        ant_min->seg = min->seg;
    }

    free(min)
}
