#include <iostream>
#include <vector>
#include <set>

void trace_path(int remaining_weight, int item, std::multiset<int> current_set, std::multiset<int> remaining_items, std::set<std::multiset<int> >& answers, std::vector<std::vector<int> > weights);

int main(int argc, char *argv[]) {
    int weight = 0;
    std::vector<int> items;
    std::cout << "Takes total weight and checks if given items can make it\n";
    std::cout << "Enter total weight\n";
    std::cin >> weight;
    std::cout << "Enter weights of items, end with q\n";
    
    int temp;
    while(std::cin >> temp){
        items.push_back(temp);
    }
    std::cout << std::endl;
    
    std::multiset<int> itemsset;
    for(auto& it: items){
        itemsset.insert(it);
    }
    
    std::multiset<int> combos;
    combos.insert(0);
    std::vector<int> empty;
    std::vector< std::vector<int> > weights(weight+1, empty);
    
    //iterates through each number in list. These loops fill the weights 2D vector
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
    //output if each combo can be gotten
    /*
    for(int i = 0; i < weight; i++){
        std::cout << (combos.count(i)!=0) << std::endl;
    }*/
    //output weights 2D vector
    
    /*
    for(int i = 0; i < weights.size(); i++){
        std::cout << i << ": ";
        for(int j = 0; j < weights[i].size(); j++){
            std::cout << weights[i][j] << " ";
        }
        std::cout << "\n";
    }*/
    
    std::set<std::multiset<int> > answer_sets;
    std::multiset<int> blankset;
    
    trace_path(weight, 0, blankset, itemsset, answer_sets, weights);
    
    
    for(auto& it: answer_sets){
        for(auto& it2: it){
            std::cout << it2 << " ";
        }
        std::cout << std::endl;
    }        
}

//traces values in weights to find unique sets that can be made out of the given items and puts it in a set of multisets
void trace_path(int remaining_weight, int item, std::multiset<int> current_set, std::multiset<int> remaining_items, std::set<std::multiset<int> >& answers, std::vector<std::vector<int> > weights){
    //add item to current set and remove it from remaining_items. Also subtract item weight from remaining_weight. If remaining_weight is 0, add current set to answerset
    if(item != 0){
        current_set.insert(item);
        remaining_weight -= item;
        if(remaining_weight == 0){
            answers.insert(current_set);
            return;
        }
        remaining_items.erase(remaining_items.find(item));
    }
    //for each path adding to remaining_weight, trace the path with each of the possible paths indicators being the new item
    for(int i = 0; i < weights[remaining_weight].size(); i++){
        if(remaining_items.count(weights[remaining_weight][i])!=0){
            trace_path(remaining_weight, weights[remaining_weight][i], current_set, remaining_items, answers, weights);
        }
    }
}
    