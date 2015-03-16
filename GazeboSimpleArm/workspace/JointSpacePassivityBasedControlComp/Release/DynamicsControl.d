################################################################################
# Automatically-generated file. Do not edit!
################################################################################

DynamicsControl.d ./DynamicsControl.o: ../DynamicsControl.cpp ../DynamicsControl.h \
 /usr/local/include/kdl/chaindynparam.hpp \
 /usr/local/include/kdl/chainidsolver_recursive_newton_euler.hpp \
 /usr/local/include/kdl/chainidsolver.hpp \
 /usr/local/include/kdl/chain.hpp /usr/local/include/kdl/segment.hpp \
 /usr/local/include/kdl/frames.hpp \
 /usr/local/include/kdl/utilities/kdl-config.h \
 /usr/local/include/kdl/utilities/utility.h \
 /usr/local/include/kdl/utilities/kdl-config.h \
 /usr/local/include/kdl/frames.inl \
 /usr/local/include/kdl/rigidbodyinertia.hpp \
 /usr/local/include/kdl/rotationalinertia.hpp \
 /usr/local/include/kdl/joint.hpp /usr/local/include/kdl/jntarray.hpp \
 /usr/local/include/kdl/jacobian.hpp /usr/eigen/Eigen/Core \
 /usr/eigen/Eigen/src/Core/util/DisableStupidWarnings.h \
 /usr/eigen/Eigen/src/Core/util/Macros.h \
 /usr/eigen/Eigen/src/Core/util/MKL_support.h \
 /usr/eigen/Eigen/src/Core/util/Constants.h \
 /usr/eigen/Eigen/src/Core/util/ForwardDeclarations.h \
 /usr/eigen/Eigen/src/Core/util/Meta.h \
 /usr/eigen/Eigen/src/Core/util/StaticAssert.h \
 /usr/eigen/Eigen/src/Core/util/XprHelper.h \
 /usr/eigen/Eigen/src/Core/util/Memory.h \
 /usr/eigen/Eigen/src/Core/NumTraits.h \
 /usr/eigen/Eigen/src/Core/MathFunctions.h \
 /usr/eigen/Eigen/src/Core/GenericPacketMath.h \
 /usr/eigen/Eigen/src/Core/arch/Default/Settings.h \
 /usr/eigen/Eigen/src/Core/Functors.h \
 /usr/eigen/Eigen/src/Core/DenseCoeffsBase.h \
 /usr/eigen/Eigen/src/Core/DenseBase.h \
 /usr/eigen/Eigen/src/Core/../plugins/BlockMethods.h \
 /usr/eigen/Eigen/src/Core/MatrixBase.h \
 /usr/eigen/Eigen/src/Core/../plugins/CommonCwiseUnaryOps.h \
 /usr/eigen/Eigen/src/Core/../plugins/CommonCwiseBinaryOps.h \
 /usr/eigen/Eigen/src/Core/../plugins/MatrixCwiseUnaryOps.h \
 /usr/eigen/Eigen/src/Core/../plugins/MatrixCwiseBinaryOps.h \
 /usr/eigen/Eigen/src/Core/EigenBase.h /usr/eigen/Eigen/src/Core/Assign.h \
 /usr/eigen/Eigen/src/Core/util/BlasUtil.h \
 /usr/eigen/Eigen/src/Core/DenseStorage.h \
 /usr/eigen/Eigen/src/Core/NestByValue.h \
 /usr/eigen/Eigen/src/Core/ForceAlignedAccess.h \
 /usr/eigen/Eigen/src/Core/ReturnByValue.h \
 /usr/eigen/Eigen/src/Core/NoAlias.h \
 /usr/eigen/Eigen/src/Core/PlainObjectBase.h \
 /usr/eigen/Eigen/src/Core/Matrix.h /usr/eigen/Eigen/src/Core/Array.h \
 /usr/eigen/Eigen/src/Core/CwiseBinaryOp.h \
 /usr/eigen/Eigen/src/Core/CwiseUnaryOp.h \
 /usr/eigen/Eigen/src/Core/CwiseNullaryOp.h \
 /usr/eigen/Eigen/src/Core/CwiseUnaryView.h \
 /usr/eigen/Eigen/src/Core/SelfCwiseBinaryOp.h \
 /usr/eigen/Eigen/src/Core/Dot.h /usr/eigen/Eigen/src/Core/StableNorm.h \
 /usr/eigen/Eigen/src/Core/MapBase.h /usr/eigen/Eigen/src/Core/Stride.h \
 /usr/eigen/Eigen/src/Core/Map.h /usr/eigen/Eigen/src/Core/Block.h \
 /usr/eigen/Eigen/src/Core/VectorBlock.h /usr/eigen/Eigen/src/Core/Ref.h \
 /usr/eigen/Eigen/src/Core/Transpose.h \
 /usr/eigen/Eigen/src/Core/DiagonalMatrix.h \
 /usr/eigen/Eigen/src/Core/Diagonal.h \
 /usr/eigen/Eigen/src/Core/DiagonalProduct.h \
 /usr/eigen/Eigen/src/Core/PermutationMatrix.h \
 /usr/eigen/Eigen/src/Core/Transpositions.h \
 /usr/eigen/Eigen/src/Core/Redux.h /usr/eigen/Eigen/src/Core/Visitor.h \
 /usr/eigen/Eigen/src/Core/Fuzzy.h /usr/eigen/Eigen/src/Core/IO.h \
 /usr/eigen/Eigen/src/Core/Swap.h \
 /usr/eigen/Eigen/src/Core/CommaInitializer.h \
 /usr/eigen/Eigen/src/Core/Flagged.h \
 /usr/eigen/Eigen/src/Core/ProductBase.h \
 /usr/eigen/Eigen/src/Core/GeneralProduct.h \
 /usr/eigen/Eigen/src/Core/TriangularMatrix.h \
 /usr/eigen/Eigen/src/Core/SelfAdjointView.h \
 /usr/eigen/Eigen/src/Core/products/GeneralBlockPanelKernel.h \
 /usr/eigen/Eigen/src/Core/products/Parallelizer.h \
 /usr/eigen/Eigen/src/Core/products/CoeffBasedProduct.h \
 /usr/eigen/Eigen/src/Core/products/GeneralMatrixVector.h \
 /usr/eigen/Eigen/src/Core/products/GeneralMatrixMatrix.h \
 /usr/eigen/Eigen/src/Core/SolveTriangular.h \
 /usr/eigen/Eigen/src/Core/products/GeneralMatrixMatrixTriangular.h \
 /usr/eigen/Eigen/src/Core/products/SelfadjointMatrixVector.h \
 /usr/eigen/Eigen/src/Core/products/SelfadjointMatrixMatrix.h \
 /usr/eigen/Eigen/src/Core/products/SelfadjointProduct.h \
 /usr/eigen/Eigen/src/Core/products/SelfadjointRank2Update.h \
 /usr/eigen/Eigen/src/Core/products/TriangularMatrixVector.h \
 /usr/eigen/Eigen/src/Core/products/TriangularMatrixMatrix.h \
 /usr/eigen/Eigen/src/Core/products/TriangularSolverMatrix.h \
 /usr/eigen/Eigen/src/Core/products/TriangularSolverVector.h \
 /usr/eigen/Eigen/src/Core/BandMatrix.h \
 /usr/eigen/Eigen/src/Core/CoreIterators.h \
 /usr/eigen/Eigen/src/Core/BooleanRedux.h \
 /usr/eigen/Eigen/src/Core/Select.h \
 /usr/eigen/Eigen/src/Core/VectorwiseOp.h \
 /usr/eigen/Eigen/src/Core/Random.h /usr/eigen/Eigen/src/Core/Replicate.h \
 /usr/eigen/Eigen/src/Core/Reverse.h \
 /usr/eigen/Eigen/src/Core/ArrayBase.h \
 /usr/eigen/Eigen/src/Core/../plugins/ArrayCwiseUnaryOps.h \
 /usr/eigen/Eigen/src/Core/../plugins/ArrayCwiseBinaryOps.h \
 /usr/eigen/Eigen/src/Core/ArrayWrapper.h \
 /usr/eigen/Eigen/src/Core/GlobalFunctions.h \
 /usr/eigen/Eigen/src/Core/util/ReenableStupidWarnings.h \
 /usr/local/include/kdl/articulatedbodyinertia.hpp \
 /usr/local/include/kdl/jntspaceinertiamatrix.hpp ../ManipulatorControl.h \
 /usr/eigen/Eigen/LU /usr/eigen/Eigen/Core \
 /usr/eigen/Eigen/src/misc/Solve.h /usr/eigen/Eigen/src/misc/Kernel.h \
 /usr/eigen/Eigen/src/misc/Image.h /usr/eigen/Eigen/src/LU/FullPivLU.h \
 /usr/eigen/Eigen/src/LU/PartialPivLU.h \
 /usr/eigen/Eigen/src/LU/Determinant.h /usr/eigen/Eigen/src/LU/Inverse.h \
 /usr/local/include/kdl/chain.hpp

../DynamicsControl.h:

/usr/local/include/kdl/chaindynparam.hpp:

/usr/local/include/kdl/chainidsolver_recursive_newton_euler.hpp:

/usr/local/include/kdl/chainidsolver.hpp:

/usr/local/include/kdl/chain.hpp:

/usr/local/include/kdl/segment.hpp:

/usr/local/include/kdl/frames.hpp:

/usr/local/include/kdl/utilities/kdl-config.h:

/usr/local/include/kdl/utilities/utility.h:

/usr/local/include/kdl/utilities/kdl-config.h:

/usr/local/include/kdl/rigidbodyinertia.hpp:

/usr/local/include/kdl/rotationalinertia.hpp:

/usr/local/include/kdl/joint.hpp:

/usr/local/include/kdl/jntarray.hpp:

/usr/local/include/kdl/jacobian.hpp:

/usr/eigen/Eigen/src/Core/util/DisableStupidWarnings.h:

/usr/eigen/Eigen/src/Core/util/Macros.h:

/usr/eigen/Eigen/src/Core/util/MKL_support.h:

/usr/eigen/Eigen/src/Core/util/Constants.h:

/usr/eigen/Eigen/src/Core/util/ForwardDeclarations.h:

/usr/eigen/Eigen/src/Core/util/Meta.h:

/usr/eigen/Eigen/src/Core/util/StaticAssert.h:

/usr/eigen/Eigen/src/Core/util/XprHelper.h:

/usr/eigen/Eigen/src/Core/util/Memory.h:

/usr/eigen/Eigen/src/Core/NumTraits.h:

/usr/eigen/Eigen/src/Core/MathFunctions.h:

/usr/eigen/Eigen/src/Core/GenericPacketMath.h:

/usr/eigen/Eigen/src/Core/arch/Default/Settings.h:

/usr/eigen/Eigen/src/Core/Functors.h:

/usr/eigen/Eigen/src/Core/DenseCoeffsBase.h:

/usr/eigen/Eigen/src/Core/DenseBase.h:

/usr/eigen/Eigen/src/Core/../plugins/BlockMethods.h:

/usr/eigen/Eigen/src/Core/MatrixBase.h:

/usr/eigen/Eigen/src/Core/../plugins/CommonCwiseUnaryOps.h:

/usr/eigen/Eigen/src/Core/../plugins/CommonCwiseBinaryOps.h:

/usr/eigen/Eigen/src/Core/../plugins/MatrixCwiseUnaryOps.h:

/usr/eigen/Eigen/src/Core/../plugins/MatrixCwiseBinaryOps.h:

/usr/eigen/Eigen/src/Core/EigenBase.h:

/usr/eigen/Eigen/src/Core/Assign.h:

/usr/eigen/Eigen/src/Core/util/BlasUtil.h:

/usr/eigen/Eigen/src/Core/DenseStorage.h:

/usr/eigen/Eigen/src/Core/NestByValue.h:

/usr/eigen/Eigen/src/Core/ForceAlignedAccess.h:

/usr/eigen/Eigen/src/Core/ReturnByValue.h:

/usr/eigen/Eigen/src/Core/NoAlias.h:

/usr/eigen/Eigen/src/Core/PlainObjectBase.h:

/usr/eigen/Eigen/src/Core/Matrix.h:

/usr/eigen/Eigen/src/Core/Array.h:

/usr/eigen/Eigen/src/Core/CwiseBinaryOp.h:

/usr/eigen/Eigen/src/Core/CwiseUnaryOp.h:

/usr/eigen/Eigen/src/Core/CwiseNullaryOp.h:

/usr/eigen/Eigen/src/Core/CwiseUnaryView.h:

/usr/eigen/Eigen/src/Core/SelfCwiseBinaryOp.h:

/usr/eigen/Eigen/src/Core/Dot.h:

/usr/eigen/Eigen/src/Core/StableNorm.h:

/usr/eigen/Eigen/src/Core/MapBase.h:

/usr/eigen/Eigen/src/Core/Stride.h:

/usr/eigen/Eigen/src/Core/Map.h:

/usr/eigen/Eigen/src/Core/Block.h:

/usr/eigen/Eigen/src/Core/VectorBlock.h:

/usr/eigen/Eigen/src/Core/Ref.h:

/usr/eigen/Eigen/src/Core/Transpose.h:

/usr/eigen/Eigen/src/Core/DiagonalMatrix.h:

/usr/eigen/Eigen/src/Core/Diagonal.h:

/usr/eigen/Eigen/src/Core/DiagonalProduct.h:

/usr/eigen/Eigen/src/Core/PermutationMatrix.h:

/usr/eigen/Eigen/src/Core/Transpositions.h:

/usr/eigen/Eigen/src/Core/Redux.h:

/usr/eigen/Eigen/src/Core/Visitor.h:

/usr/eigen/Eigen/src/Core/Fuzzy.h:

/usr/eigen/Eigen/src/Core/IO.h:

/usr/eigen/Eigen/src/Core/Swap.h:

/usr/eigen/Eigen/src/Core/CommaInitializer.h:

/usr/eigen/Eigen/src/Core/Flagged.h:

/usr/eigen/Eigen/src/Core/ProductBase.h:

/usr/eigen/Eigen/src/Core/GeneralProduct.h:

/usr/eigen/Eigen/src/Core/TriangularMatrix.h:

/usr/eigen/Eigen/src/Core/SelfAdjointView.h:

/usr/eigen/Eigen/src/Core/products/GeneralBlockPanelKernel.h:

/usr/eigen/Eigen/src/Core/products/Parallelizer.h:

/usr/eigen/Eigen/src/Core/products/CoeffBasedProduct.h:

/usr/eigen/Eigen/src/Core/products/GeneralMatrixVector.h:

/usr/eigen/Eigen/src/Core/products/GeneralMatrixMatrix.h:

/usr/eigen/Eigen/src/Core/SolveTriangular.h:

/usr/eigen/Eigen/src/Core/products/GeneralMatrixMatrixTriangular.h:

/usr/eigen/Eigen/src/Core/products/SelfadjointMatrixVector.h:

/usr/eigen/Eigen/src/Core/products/SelfadjointMatrixMatrix.h:

/usr/eigen/Eigen/src/Core/products/SelfadjointProduct.h:

/usr/eigen/Eigen/src/Core/products/SelfadjointRank2Update.h:

/usr/eigen/Eigen/src/Core/products/TriangularMatrixVector.h:

/usr/eigen/Eigen/src/Core/products/TriangularMatrixMatrix.h:

/usr/eigen/Eigen/src/Core/products/TriangularSolverMatrix.h:

/usr/eigen/Eigen/src/Core/products/TriangularSolverVector.h:

/usr/eigen/Eigen/src/Core/BandMatrix.h:

/usr/eigen/Eigen/src/Core/CoreIterators.h:

/usr/eigen/Eigen/src/Core/BooleanRedux.h:

/usr/eigen/Eigen/src/Core/Select.h:

/usr/eigen/Eigen/src/Core/VectorwiseOp.h:

/usr/eigen/Eigen/src/Core/Random.h:

/usr/eigen/Eigen/src/Core/Replicate.h:

/usr/eigen/Eigen/src/Core/Reverse.h:

/usr/eigen/Eigen/src/Core/ArrayBase.h:

/usr/eigen/Eigen/src/Core/../plugins/ArrayCwiseUnaryOps.h:

/usr/eigen/Eigen/src/Core/../plugins/ArrayCwiseBinaryOps.h:

/usr/eigen/Eigen/src/Core/ArrayWrapper.h:

/usr/eigen/Eigen/src/Core/GlobalFunctions.h:

/usr/eigen/Eigen/src/Core/util/ReenableStupidWarnings.h:

/usr/local/include/kdl/articulatedbodyinertia.hpp:

/usr/local/include/kdl/jntspaceinertiamatrix.hpp:

../ManipulatorControl.h:

/usr/eigen/Eigen/src/misc/Solve.h:

/usr/eigen/Eigen/src/misc/Kernel.h:

/usr/eigen/Eigen/src/misc/Image.h:

/usr/eigen/Eigen/src/LU/FullPivLU.h:

/usr/eigen/Eigen/src/LU/PartialPivLU.h:

/usr/eigen/Eigen/src/LU/Determinant.h:

/usr/eigen/Eigen/src/LU/Inverse.h:

/usr/local/include/kdl/chain.hpp:

