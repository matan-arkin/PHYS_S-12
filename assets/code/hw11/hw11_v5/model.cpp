/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

// Automatically created from a TensorFlow Lite flatbuffer using the command:
// xxd -i model.tflite > model.cc

// This is a standard TensorFlow Lite model file that has been converted into a
// C data array, so it can be easily compiled into a binary for devices that
// don't have a file system.

// See train/README.md for a full description of the creation process.

#include "model.h"

// Keep model aligned to 8 bytes to guarantee aligned 64-bit accesses.
alignas(8) const unsigned char g_model[] = {
  0x8c, 0x48, 0xe8, 0x3d, 0xd2, 0x4a, 0x21, 0xbe, 0x26, 0xfe, 0xff, 0xff,
  0x10, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x24, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x73, 0x74, 0x64, 0x2e,
  0x63, 0x6f, 0x6e, 0x73, 0x74, 0x61, 0x6e, 0x74, 0x31, 0x00, 0x00, 0x00,
  0xac, 0xfd, 0xff, 0xff, 0x76, 0xfe, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00,
  0x40, 0x00, 0x00, 0x00, 0xf7, 0xc0, 0x0e, 0x3f, 0x93, 0x1e, 0xe3, 0x3d,
  0xe4, 0xaf, 0x48, 0xbc, 0x6e, 0x85, 0x04, 0xbe, 0xc1, 0xa9, 0xbd, 0x3d,
  0xfd, 0x56, 0x09, 0xbf, 0x88, 0x1c, 0xc4, 0xbe, 0x65, 0xc3, 0x81, 0x3e,
  0x00, 0x85, 0x1d, 0xbc, 0xae, 0x51, 0x3b, 0xbe, 0x6b, 0xfe, 0x37, 0x3e,
  0x8e, 0x51, 0xa9, 0xbe, 0x51, 0x1a, 0xe7, 0x3e, 0x5c, 0x6f, 0xf0, 0x3e,
  0xb1, 0xb6, 0xb2, 0x3d, 0xec, 0x65, 0x0f, 0xbe, 0xaa, 0xfe, 0xff, 0xff,
  0x10, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x24, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x73, 0x74, 0x64, 0x2e,
  0x63, 0x6f, 0x6e, 0x73, 0x74, 0x61, 0x6e, 0x74, 0x00, 0x00, 0x00, 0x00,
  0x30, 0xfe, 0xff, 0xff, 0xfa, 0xfe, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00,
  0x40, 0x00, 0x00, 0x00, 0x1a, 0xc7, 0xa4, 0xbf, 0x21, 0xb5, 0xf1, 0x3d,
  0x59, 0xcc, 0x44, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x85, 0x27, 0xbf,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb9, 0xc5, 0xc7, 0x3e,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x7a, 0x66, 0xbf,
  0x00, 0x00, 0x00, 0x00, 0x0f, 0x22, 0x94, 0xbe, 0x4b, 0x7f, 0x03, 0x3d,
  0x7b, 0x4c, 0x0b, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x2e, 0xff, 0xff, 0xff,
  0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x64, 0x65, 0x6e, 0x73, 0x65, 0x5f, 0x32, 0x2f,
  0x62, 0x69, 0x61, 0x73, 0x00, 0x00, 0x00, 0x00, 0xb0, 0xfe, 0xff, 0xff,
  0x7a, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0xa6, 0x58, 0x3d,
  0x80, 0x7f, 0x7b, 0x3d, 0x81, 0x9a, 0x92, 0xbd, 0x79, 0x8c, 0xcc, 0xbc,
  0x7a, 0x3c, 0x0c, 0xbd, 0x4b, 0x22, 0xac, 0xbd, 0x00, 0x00, 0x00, 0x00,
  0xb7, 0x29, 0x44, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xe3, 0x7f, 0x9b, 0xbd, 0xe7, 0x1b, 0x86, 0xbd,
  0x00, 0x00, 0x00, 0x00, 0xae, 0xff, 0xff, 0xff, 0x10, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x64, 0x65, 0x6e, 0x73, 0x65, 0x5f, 0x33, 0x2f, 0x62, 0x69, 0x61, 0x73,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x06, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x06, 0x00, 0x08, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x3a, 0xcd, 0x89, 0xbd,
  0x00, 0x00, 0x0e, 0x00, 0x14, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00,
  0x0c, 0x00, 0x10, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x64, 0x65, 0x6e, 0x73, 0x65, 0x5f, 0x34, 0x2f, 0x62, 0x69, 0x61, 0x73,
  0x00, 0x00, 0x00, 0x00, 0x90, 0xff, 0xff, 0xff, 0x14, 0x00, 0x18, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x08, 0x00, 0x0c, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x14, 0x00, 0x14, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00,
  0x34, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x73, 0x65, 0x72, 0x76,
  0x69, 0x6e, 0x67, 0x5f, 0x64, 0x65, 0x66, 0x61, 0x75, 0x6c, 0x74, 0x5f,
  0x64, 0x65, 0x6e, 0x73, 0x65, 0x5f, 0x32, 0x5f, 0x69, 0x6e, 0x70, 0x75,
  0x74, 0x3a, 0x30, 0x00, 0x02, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0x01, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x04, 0x00, 0x04, 0x00,
  0x04, 0x00, 0x00, 0x00
};
const int g_model_len = 2788;
