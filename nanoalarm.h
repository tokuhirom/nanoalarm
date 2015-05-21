/*
 * The MIT License (MIT)
 * Copyright (C) 2015 Tokuhiro Matsuno, http://64p.org/ <tokuhirom@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the “Software”), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef NANOALARM_H_
#define NANOALARM_H_

#include <signal.h>
#include <unistd.h>

namespace nanoalarm {
    class Alarm {
    private:
        unsigned int last_seconds_;
        struct sigaction last_sa_;
        static void nop_sighandler(int signum) { signum = signum; }
    public:
        Alarm(unsigned int seconds) {
            last_seconds_ = alarm(seconds);

            sigset_t block;
            sigemptyset( &block );

            struct sigaction sa;
            sa.sa_mask    = block;
            sa.sa_handler = &Alarm::nop_sighandler;
            sa.sa_flags   = 0;
            sigaction(SIGALRM, &sa, &last_sa_);
        }
        ~Alarm() {
            alarm(last_seconds_);
            sigaction(SIGALRM, &last_sa_, NULL);
        }
    };
}

#endif // NANOALARM_H_
