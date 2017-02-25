//
// Created by c6s on 17-2-23.
//

#ifndef TINYNL_BUFFER_H
#define TINYNL_BUFFER_H

#include <tinyNL/dir/Noncopyable.h>
#include <vector>

namespace tinyNL {
    namespace net {
        class Socket;
        //not thread safe
        class Buffer : Noncopyable {
        public:
            using Pos = std::vector<char>::size_type;
            explicit Buffer():
            upperLimit(1024){};
            ~Buffer()= default;
//            void readFromSocket(Socket &);
//            void writeToSocket(Socket &);
            void append(const char* src, size_t len);
            void erase(size_t len);
            bool empty()const{return innerbuf_.size() == 0;}
            size_t readableSize() const{return writeIdx - readIdx;}
            char* readPtr(){return &innerbuf_[readIdx];}
        private:
            std::vector<char> innerbuf_;
            std::vector<char>::size_type upperLimit;
            Pos readIdx;
            Pos writeIdx;
            bool needShrimp(Pos blankLen){return blankLen > 256;}
        };
    }
}


#endif //TINYNL_BUFFER_H