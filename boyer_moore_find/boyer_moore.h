#include <string.h>
#include <limits.h>
#include <stdbool.h>

/** <p>Функция сравнения суффиксов</p>
  * 
  * @param needle "иголка" - подстрока, которую мы ищем
  * @param nlen  длина needle
  * @param offset - позиция конца суффикса
  * @param suffixlen - его длина
  * @return true, если есть совпадение суффикса (и нет совпадения более длинного суффикса)
  */
static bool suffix_match
    (const unsigned char *needle, size_t nlen, 
     size_t offset, size_t suffixlen)
{
    if (offset > suffixlen)
        return needle[offset - suffixlen - 1] != needle[nlen - suffixlen - 1] &&
            memcmp(needle + nlen - suffixlen, needle + offset - suffixlen, suffixlen) == 0;
    else
        return memcmp(needle + nlen - offset, needle, offset) == 0;
}

/** <p>Функция сравнения длин</p>
  * 
  * @param a длина a
  * @param b длина b
  * @return наибольшую длину
  */
static size_t max(size_t a, size_t b)
{
    if( a > b){
        return a;
    } 
    else{
        return b;
    }
}

/** <p>Функция поиска подстроки в строке алгоритмом Боуэра-Мура</p>
  * 
  * @param haystack "стог" -строка, в которой выполняется поиск
  * @param needle  "иголка" - подстрока, инддекс вхождения которой выводится
  * @param hlen - длина haystack
  * @param nlen - длина needle
  * @return указатель на первое вхождение needle в haystack, либо NULL
  */
const unsigned char* bm_find
    (const unsigned char* haystack, size_t hlen,
     const unsigned char* needle,   size_t nlen)
{
    size_t skip[nlen];          /* Таблица суффиксов */
    size_t occ[UCHAR_MAX + 1]; /* Таблица стоп-символов */
    
    if(nlen > hlen || nlen <= 0 || !haystack || !needle) 
        return NULL;

    /* ПОСТРОЕНИЕ ТАБЛИЦЫ СТОП-СИМВОЛОВ */
    
    /* Заполняем -1 (в Си нумерация символов с 0!!) */
    for(size_t a = 0; a < UCHAR_MAX+1; ++a)
        occ[a] = -1;
    
    /* В таблицу occ записывается последнее вхождение в needle  */
    /* (исключая последний символ) */
    for(size_t a = 0; a < nlen - 1; ++a) 
        occ[needle[a]] = a;
    
    /* ПОСТРОЕНИЕ ТАБЛИЦЫ СУФФИКСОВ */  
    for(size_t a = 0; a < nlen; ++a)
    {
        size_t offs = nlen;
        while(offs && !suffix_match(needle, nlen, offs, a))
            --offs;
        skip[nlen - a - 1] = nlen - offs;
    }
    
    /* ПОИСК */
    for(size_t hpos = 0; hpos <= hlen - nlen; )
    {
        size_t npos = nlen - 1;
        /* Сверка needle и haystack с конца */
        while(needle[npos] == haystack[npos + hpos])
        {
            if(npos == 0) 
                return haystack + hpos;

            --npos;
        }
        /* Не совпало! */
        hpos += max(skip[npos], npos - occ[haystack[npos + hpos]]);
        /*          ^^^         ^^^^                               */
        /*        суффикс     стоп-символ                          */
    }
    return NULL;
}