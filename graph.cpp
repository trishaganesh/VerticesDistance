
//book reference 
#include <bits/stdc++.h>

namespace main_savitch_15
{
//textbook reference
    template <class Item>
    const std::size_t graph<Item>::MAXIMUM;

    template <class Item>
    void graph<Item>::add_edge(std::size_t source, std::size_t target)
    {
        assert(source < size( ));
        assert(target < size( ));
        edges[source][target] = true;
    }

    template <class Item>
    void graph<Item>::add_vertex(const Item& label)
    {
        std::size_t newElement;
        std::size_t tempVar;

        assert(size( ) < MAXIMUM);
        newElement = many_vertices;
        many_vertices++;
        for (tempVar = 0; tempVar < many_vertices; ++tempVar)
        {
            edges[tempVar][newElement] = false;
            edges[newElement][tempVar] = false;
        }
        labels[newElement] = label;
    }

    template <class Item>
    bool graph<Item>::is_edge(std::size_t source, std::size_t target) const
    {
        assert(source < size( ));
        assert(target < size( ));
        return edges[source][target];
    }

    template <class Item>
    Item& graph<Item>::operator[ ] (std::size_t vertex)
    {
        assert(vertex < size( ));
        return labels[vertex];     
    }

    template <class Item>
    Item graph<Item>::operator[ ] (std::size_t vertex) const
    {
        assert(vertex < size( ));
        return labels[vertex];     
    }

    template <class Item>
    std::set<std::size_t> graph<Item>::neighbors(std::size_t vertex) const

    {
        std::set<std::size_t> solutionProblem;
        std::size_t x;

        assert(vertex < size( ));

        for (x = 0; x < size( ); ++x)
        {
            if (edges[vertex][x])
                solutionProblem.insert(x);
        }
        return solutionProblem;
    }

    template <class Item>
    void graph<Item>::remove_edge(std::size_t source, std::size_t target)
    {
        assert(source < size( ));
        assert(target < size( ));
        edges[source][target] = false;
    }

    template <class Item>
    std::size_t graph<Item>::longestDistance(Item start, Item end) 
    {
    
        std::size_t indexBegin, indexEnding;
        for(std::size_t x = 0; x < many_vertices; x++)
        {
            if(labels[x] == start) indexBegin = x;
            if(labels[x] == end) indexEnding = x;
        }

        if(many_vertices == 0) return 0;

        bool value[many_vertices];
        int placehold[many_vertices];
        for(int x = 0; x < many_vertices; x++)
        {
            value[x] = false;
            placehold[x] = 0;
        }

        std::queue<std::size_t> verticesLocations;
        verticesLocations.push(indexBegin);

        while(!verticesLocations.empty())
        {
            std::size_t existingVertex = verticesLocations.front();
            verticesLocations.pop();

            value[existingVertex] = true;

            auto neighborElement = neighbors(existingVertex);

            for(std::size_t x : neighborElement)
            {
                if(!value[x])
                {
                    std::size_t newPlaceholder = placehold[existingVertex] + 1;

                    if(newPlaceholder > placehold[x])
                    {
                        placehold[x] = newPlaceholder;
                        verticesLocations.push(x);
                    }
                }
            }
        }

        return placehold[indexEnding];
    }
}
