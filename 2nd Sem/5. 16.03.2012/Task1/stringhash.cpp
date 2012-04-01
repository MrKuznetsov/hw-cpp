#include "stringhash.h"

StringHash::StringHash()
{
}


HashList *StringHash::add(string str)
{
    return aHash[func->call(str)].add(str);
}

void StringHash::remove(string str)
{
    aHash[func->call(str)].remove(str);
}

HashList *StringHash::find(string str)
{
    return aHash[func->call(str)].find(str);
}

void StringHash::status()
{
    StringList *tmp = 0;
    int elemcount = 0;
    for (int i = 0; i < N_HASH; i++)
        if (aHash[i].next)
            for (tmp = aHash[i].next; tmp; tmp = tmp->next)
            {
                printf("Count of \"%s\" is %d\n", tmp->str.c_str(), tmp->count);
                elemcount++;
            };

    int free = 0;
    for (int i = 0; i < N_HASH; i++)
        if (!aHash[i].next)
            free++;
    printf("\n Stats:\n");
    printf("Count of FREE cells is %d(%d)\n", free, N_HASH);
    printf("Load factor is %f\n", float(elemcount)/float(N_HASH));
    int coll = 0;
    for (int i = 0; i < N_HASH; i++)
        if (aHash[i].next && aHash[i].next->next)
            coll++;
    printf("Count of collisions is %d\n", coll);

}
