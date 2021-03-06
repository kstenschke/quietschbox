/*
  Copyright (c) Kay Stenschke
  All rights reserved.
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
   * Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   * Neither the name of  nor the names of its contributors may be used to
     endorse or promote products derived from this software without specific
     prior written permission.
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef QUIETSCHBOX_MODEL_GENERATOR_H_
#define QUIETSCHBOX_MODEL_GENERATOR_H_

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <helper/helper_system.h>
#include <struct/pitch.h>

class WaveGenerator {
 public:
  explicit WaveGenerator(double hz = 44100);

  WaveGenerator* GenerateTone(uint8_t tone, double seconds = 0.5,
                              uint8_t cut_off = 0,
                              double pi_factor = 2.0,
                              double slow_down_curve = 1.0,
                              double saw_tooth_divider = 100.0,
                              uint32_t saw_tooth_length = 0);

  WaveGenerator* GenerateSilence(double seconds);

  void ConcatTones(const std::string& filename_result,
                   bool rem_tmp_files = true);

 private:
  uint8_t index_tone_ = 0;

  double hz_;

  void GenerateFreq(double frequency,
                    double seconds,
                    const std::string& filename,
                    uint8_t cut_off = 0,
                    double pi_factor = 2.0,
                    double slow_down_curve = 1.0,
                    double saw_tooth_divider = 100.0,
                    uint32_t saw_tooth_length = 0);

  static void WriteWord(std::ostream &outs, uint64_t value, uint16_t size = 0);

  static double GetFrequencyByTone(uint8_t tone);
};

#endif //QUIETSCHBOX_MODEL_GENERATOR_H_
