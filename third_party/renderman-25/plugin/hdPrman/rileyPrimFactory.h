//
// Copyright 2023 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#ifndef EXT_RMANPKG_25_0_PLUGIN_RENDERMAN_PLUGIN_HD_PRMAN_RILEY_PRIM_FACTORY_H
#define EXT_RMANPKG_25_0_PLUGIN_RENDERMAN_PLUGIN_HD_PRMAN_RILEY_PRIM_FACTORY_H

#include "pxr/pxr.h"
#include "hdPrman/api.h"
#include "hdPrman/sceneIndexObserverApi.h"

#ifdef HDPRMAN_USE_SCENE_INDEX_OBSERVER

#include "pxr/imaging/hdsi/primManagingSceneIndexObserver.h"

PXR_NAMESPACE_OPEN_SCOPE

class HdPrman_RenderParam;

using HdPrman_RileyPrimFactoryHandle =
    std::shared_ptr<class HdPrman_RileyPrimFactory>;

/// \class HdPrman_RileyPrimFactory
///
/// Implements HdsiPrimManagingSceneIndexObserver::PrimFactoryBase
/// to translate scene index prims into Riley::Create/Modify/DeleteFoo
/// calls.
///
class HdPrman_RileyPrimFactory
   : public HdsiPrimManagingSceneIndexObserver::PrimFactoryBase
{
public:
    /// HdPrman_RenderParam's needed to access Riley.
    HdPrman_RileyPrimFactory(
        HdPrman_RenderParam * renderParam);

    HdsiPrimManagingSceneIndexObserver::PrimBaseHandle
    CreatePrim(
        const HdSceneIndexObserver::AddedPrimEntry &entry,
        const HdsiPrimManagingSceneIndexObserver * observer) override;

private:
    HdPrman_RenderParam * const _renderParam;
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif // #ifdef HDPRMAN_USE_SCENE_INDEX_OBSERVER

#endif

