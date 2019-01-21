#include <iostream>
#include <vector>
#include <set>

void trace_path(int remaining_weight, int item, std::multiset<int> current_multiset, std::multiset<int> remaining_items, std::set<std::multiset<int> >& answers, std::vector<std::vector<int> > weights);

int main(int argc, char *argv[]) {
    int weight = 0;
    std::vector<int> items;
    std::cout << "Takes total weight and checks if given items can make it\n";
    std::cout << "Enter total weight\n";
    std::cin >> weight;
    std::cout << "Enter weights of items, end with q\n";
    
    
    /*int weight = 12;
    std::vector<int> items;
    items.push_back(3);
    items.push_back(5);
    items.push_back(7);
    items.push_back(4);
    items.push_back(2);
    */
    
    
    int temp;
    while(std::cin >> temp){
        items.push_back(temp);
    }
    
    
    std::multiset<int> itemsmultiset;
    for(auto& it: items){
        itemsmultiset.insert(it);
        std::cout << it;
    }
    for(auto& it: itemsmultiset){
        std::cout << it << " ";
    }
    
    std::multiset<int> combos;
    combos.insert(0);
    //std::vector<bool> weightexists(weight+1, false);
    //weightexists[0] = true;
    //std::vector<int> weightcombos(weight+1, 0);
    std::vector<int> empty;
    std::vector< std::vector<int> > weights(weight+1, empty);
    
    //iterates through each number in list
    for(int i = 0; i < items.size(); i++){
        if(items[i] <= weight){
            //iterates through each weight in checklist
            for(int j = weight; j>= items[i]; j--){
                if(combos.count(j-items[i])!=0){
                    combos.insert(j);
                    weights[j].push_back(items[i]);
                }
            }
        }
    }
    
    for(int i = 0; i < weight; i++){
        std::cout << (combos.count(i)!=0) << std::endl;
    }
    for(int i = 0; i < weights.size(); i++){
        std::cout << i << ": ";
        for(int j = 0; j < weights[i].size(); j++){
            std::cout << weights[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    std::set<std::multiset<int> > answer_multisets;
    std::multiset<int> blankmultiset;
    
    trace_path(weight, 0, blankmultiset, itemsmultiset, answer_multisets, weights);
    
    /*for(int i = 0; i < weights[weight]; i++){
        std::multiset<int> temp_multiset;
        temp_multiset.insert(weights[weight][i]);
        int remaining_weight = weight - weights[weight][i];
        while(true){
            if(remaining_weight <= 0){
                
                        
               
            }
        }
    }
    */
    for(auto& it: answer_multisets){
        for(auto& it2: it){
            std::cout << it2 << " ";
        }
        std::cout << std::endl;
    }        
}



void trace_path(int remaining_weight, int item, std::multiset<int> current_multiset, std::multiset<int> remaining_items, std::set<std::multiset<int> >& answers, std::vector<std::vector<int> > weights){
    if(item != 0){
        current_multiset.insert(item);
        remaining_weight -= item;
        if(remaining_weight == 0){
            answers.insert(current_multiset);
            return;
        }
        remaining_items.erase(remaining_items.find(item));
    }
    for(int i = 0; i < weights[remaining_weight].size(); i++){
        if(remaining_items.count(weights[remaining_weight][i])!=0){
            trace_path(remaining_weight, weights[remaining_weight][i], current_multiset, remaining_items, answers, weights);
        }
    }
}
    