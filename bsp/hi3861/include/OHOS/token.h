/*
 * Copyright (c) 2020 Huawei Device Co., Ltd.
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
 */

#ifndef TOKEN_API_H
#define TOKEN_API_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define TOKEN_ELEMENT_SIZE 64

typedef struct {
    char uuid[TOKEN_ELEMENT_SIZE];
    char license[TOKEN_ELEMENT_SIZE];
} DevToken;

/**
 * @brief Read token value form device.
 *
 * @param token The device token info.
 * @returns 0 if it succeeds, -1 if it fails.
 */
int ReadToken(DevToken *token);

/**
 * @brief Write token value to device.
 *
 * @param token The device token info.
 * @returns 0 if it succeeds, -1 if it fails.
 */
int WriteToken(const DevToken *token);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif  // TOKEN_API_H
