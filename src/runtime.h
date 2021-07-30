/* Copyright 2021 NVIDIA Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#pragma once

#include "legion.h"

#include "core/typedefs.h"

namespace legate {

extern uint32_t extract_env(const char* env_name,
                            const uint32_t default_value,
                            const uint32_t test_value);

class Core {
 public:
  static void parse_config(void);
  static void shutdown(void);
  // Get layout constraints
  static Legion::LayoutConstraintID get_soa_layout(void);
  static Legion::LayoutConstraintID get_reduction_layout(Legion::ReductionOpID redop);
  static Legion::LayoutConstraintID get_virtual_layout(void);

 public:
  // Configuration settings
  static bool show_progress;
#ifdef LEGATE_USE_CUDA
 public:
  static cublasContext* get_cublas(void);
#endif
};

}  // namespace legate
