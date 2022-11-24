// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful
template<class TYPE>
void swap(TYPE& a, TYPE& b) {
    TYPE tmp = a;
    a = b;
    b = tmp;
}

template<class IT, class LAMBDA>
void my_selection_sort( IT begin, IT end, LAMBDA l)
{
    IT indexMin;
    IT index;
    for (auto it = begin; it != end; it++) {
        indexMin = it;
        index = it;
        index++;
        for (auto it2 = index; it2 != end; it2++) {
            if (l(*it2, *indexMin)) {
                indexMin = it2;
            }
        }

        if (indexMin != it) {
            auto tmp = *indexMin;
            *indexMin = *it;
            *it = tmp;
            
        }
    }
}


