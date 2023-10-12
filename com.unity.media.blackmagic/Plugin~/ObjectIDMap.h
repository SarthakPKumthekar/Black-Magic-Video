#pragma once

#include "Common.h"
#include <unordered_map>

namespace MediaBlackmagic
{
    // A simple object mapper class that binds object pointers and integer IDs.
    template <typename T> class ObjectIDMap final
    {
    public:

        void Add(T* instance)
        {
            static int counter = 1;
            map_[counter++] = instance;
        }

        void Remove(T* instance)
        {
            map_.erase(GetID(instance));
        }

        T* operator [] (int id) const
        {
            return map_.at(id);
        }

        int GetID(T* instance) const
        {
            for (auto it = map_.begin(); it != map_.end(); ++it)
                if (it->second == instance) return it->first;
            return -1;
        }

        size_t ObjectCount() const
        {
            return map_.size();
        }

    private:

        std::unordered_map<int, T*> map_;
    };
}
