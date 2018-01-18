////////////////////////////////////////////////////////////////////////////
//
// Copyright 2017 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////

#import <Foundation/Foundation.h>

#import "RLMResults.h"
#import "RLMArray.h"
#import "RLMObject.h"

@class RLMSyncPermission, RLMPermissionUser;

// A private subclass of `RLMResults`.
@interface RLMSyncPermissionResults : RLMResults<RLMSyncPermission *>
@end

RLM_ARRAY_TYPE(RLMPermission);
RLM_ARRAY_TYPE(RLMPermissionUser);

@interface RLMPermissionRole : RLMObject
@property (nonatomic) NSString *name;
@property (nonatomic) RLMArray<RLMPermissionUser *><RLMPermissionUser> *users;
@end

@interface RLMPermissionUser : RLMObject
@property (nonatomic) NSString *identity;
@property (nonatomic, readonly) RLMLinkingObjects<RLMPermissionRole *> *roles;
@end

@interface RLMPermission : RLMObject
@property (nonatomic) RLMPermissionRole *role;
@property (nonatomic) bool canRead;
@property (nonatomic) bool canUpdate;
@property (nonatomic) bool canDelete;
@property (nonatomic) bool canSetPermissions;
@property (nonatomic) bool canQuery;
@property (nonatomic) bool canCreate;
@property (nonatomic) bool canModifySchema;
@end

@interface RLMPermissionClass : RLMObject
@property (nonatomic) NSString *name;
@property (nonatomic) RLMArray<RLMPermission *><RLMPermission> *permissions;
@end

struct RLMPrivileges {
    bool read : 1;
    bool update : 1;
    bool del : 1;
    bool setPermissions : 1;
    bool query : 1;
    bool create : 1;
    bool modifySchema : 1;
};
