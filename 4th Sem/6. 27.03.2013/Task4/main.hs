import Data.List
import Data.Maybe
     
type Id = Int
    
type Weight = Int
     
type Edge = ( Id, Id )
     
type Graph = [ ( Edge, Weight ) ]
    
data Cost = Finite Weight | Infinity
                deriving ( Eq, Ord, Show )
     
type PathCost = ( Cost, Id )
     
edges :: Graph -> Int
edges = length

          
totalWeight :: Graph -> Weight
totalWeight = sum . map snd
     
nodes :: Graph -> [ Id ]
nodes = nub . fst . unzip . map fst

    
addCosts :: Cost -> Cost -> Cost
addCosts (Finite weightA) (Finite weightB) = Finite ( weightA + weightB )
addCosts _ _ = Infinity
     
	 
lookUp :: Edge -> Graph -> Cost
lookUp edge = maybe Infinity Finite . lookup edge
     
remove :: Eq a => a -> [ a ] -> [ a ]
remove = flip (\\) . flip (:) []

instance Num Cost 
	where (+) = addCosts

allPaths :: Graph -> [ PathCost ]
allPaths graph = addRemainingPaths [((lookUp ( 0 , node ) graph), node) | node <- nodes graph] []
       where
        addRemainingPaths :: [ PathCost ] -> [ PathCost ] -> [ PathCost ]
        addRemainingPaths [] acc = acc
        addRemainingPaths ps acc
           = addRemainingPaths (map relaxation (remove minp ps)) (minp : acc)
             where
              minp@(cmin, j) = minimum ps
              relaxation (c,i) = (c', i)
               where
                c' = min c ( cmin  + ( lookUp (j,i) graph ) )

     
--remove :: Eq a => a -> [ a ] -> [ a ]
 -----------------------------------------------------------------
